/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/27 13:39:17 by tfleming          #+#    #+#             */
/*   Updated: 2015/04/27 16:58:37 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <stdio.h>

void				see_touch()
{
	char			buffer[3];

	while (1)
	{
		read(0, buffer, 3);
		if (buffer[0] == 27)
			printf("it's an arrow\n");
		else if (buffer[0] == 4)
			printf("control+D\n");
		else
			printf("other something\n");
		printf("\n");
	}
}

t_environment		*get_set_environment(t_environment *new_env)
{
	static t_environment	*stored_env = NULL;
	
	if (new_env)
	{
		stored_env = new_env;
	}
	return (stored_env);
}

void				set_window_size()
{
	t_environment	*env;
	struct winsize	window;

	ioctl(0, TIOCGWINSZ, &window);
	env = get_set_environment(NULL);
	env->column_width = window.ws_row;
	env->column_height = window.ws_col;
	printf("row: %i \n colums:%i \n", env->column_width, env->column_height);
}

int					main(int argc, char **argv)
{
	t_environment	*env;

	signal(SIGWINCH, set_window_size);
	env = malloc(sizeof(t_environment));
	get_set_environment(env);
	char			*terminal_name;

	if (!(terminal_name = getenv("TERM")))
	 	return (-1);
	tgetent(NULL, terminal_name); // no error check because ERR not defined
	// put stuff into term
	see_touch();
	(void)argc;
	(void)argv;
	return (0);
}
