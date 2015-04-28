/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/27 13:39:17 by tfleming          #+#    #+#             */
/*   Updated: 2015/04/28 21:38:52 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void				print_selected(t_environment *env)
{
	clear_screen_from_text(env);
	
	exit(0);
}

void				wait_for_keypress()
{
	unsigned long	buffer;
	t_environment   *env;

	env = get_set_environment(NULL);
	while (buffer = 0, (read(0, &buffer, 6)) != 0)
	{
		if (buffer == KEY_BACKSPACE)
			ft_remove_nth_from_array(env->current_argument, (void**)env->words, &env->words_count);
		else if (buffer == KEY_SPACE)
		{
			if (env->highlighted[env->current_argument] == 1)
				env->highlighted[env->current_argument] = 0;
			else
				env->highlighted[env->current_argument] = 1;
			env->current_argument = (env->current_argument == env->words_count - 1 ? 0 : env->current_argument + 1);
		}
		else if (buffer == KEY_ENTER)
			print_selected(env);
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

void				set_startup()
{
	t_environment	*env;

	env = get_set_environment(NULL);
	tcgetattr(0, &env->term);
	env->term.c_lflag &= ~(ICANON);
	env->term.c_lflag &= ~(ECHO);
	env->term.c_cc[VMIN] = 1;
	env->term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &env->term) == -1)
		exit (1);
}

int					main(int argc, char **argv)
{
	t_environment	*env;

	if (argc < 2)
		return (-1);
	setup_terminal();
	env = malloc(sizeof(t_environment));
	env->words = argv + 1;
	env->current_argument = 0;
	env->highlighted = (int*)malloc(sizeof(int) * (argc - 1));
	ft_bzero(env->highlighted, argc - 1);
	env->words_count = argc - 1;
	get_set_environment(env);
	set_signals();
	set_startup();
	print_words();
	wait_for_keypress();
	return (0);
}
