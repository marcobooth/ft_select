/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/27 13:39:17 by tfleming          #+#    #+#             */
/*   Updated: 2015/04/28 11:51:21 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void				wait_for_keypress()
{
	char			buffer[3];

	while (1)
	{
		read(0, buffer, 3);
		// will not show up
		if (buffer[0] == 27)
			ft_printf("it's an arrow\n");
		else if (buffer[0] == 4)
			ft_printf("control+D\n");
		else
			ft_printf("other something\n");
		ft_printf("\n");
		print_words();
	}
}

static void			set_signals(void)
{
	signal(SIGWINCH, print_words);
}

static void			setup_terminal(void)
{
	char			*terminal_name;

	if (!(terminal_name = getenv("TERM")))
	 	ft_putendl_exit("Error getting env->TERM", 1);
	tgetent(NULL, terminal_name);
}

int					main(int argc, char **argv)
{
	t_environment	*env;

	if (argc < 2)
		return (-1);
	setup_terminal();
	env = malloc(sizeof(t_environment));
	env->words = argv + 1;
	env->words_count = argc - 1;
	get_set_environment(env);
	set_signals();
	print_words();
	wait_for_keypress();		
	return (0);
}
