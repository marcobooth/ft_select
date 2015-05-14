/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/27 13:39:17 by tfleming          #+#    #+#             */
/*   Updated: 2015/05/14 23:43:28 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
** In this file we have two static functions that reference one
** another. The 42 norme does not allow for us to have function
** prototypes in .c files. In order to get around this, we call
** set_signals with the pointer to the restart function.
*/

static void			set_signals(void (*restart_function)(int))
{
	signal(SIGWINCH, refresh_screen);
	signal(SIGCONT, restart_function);
	signal(SIGTSTP, abort_no_exit);
	signal(SIGINT, abort_exit);
	signal(SIGINT, abort_exit);
	signal(SIGHUP, abort_exit);
	signal(SIGTERM, abort_exit);
	signal(SIGSEGV, abort_exit);
	signal(SIGQUIT, abort_exit);
	signal(SIGFPE, abort_exit);
	signal(SIGALRM, abort_exit);
	signal(SIGKILL, abort_exit);
	signal(SIGABRT, abort_exit);
	signal(SIGUSR1, abort_exit);
	signal(SIGUSR2, abort_exit);
}

static void			setup_terminal(t_environment *env)
{
	char			*terminal_name;

	if (!(terminal_name = getenv("TERM")))
		ft_putendl_exit("Error getting env->TERM", 1);
	if (tgetent(NULL, terminal_name) <= 0)
	{
		ft_putendl_fd("Error getting env->TERM", 2);
		exit(1);
	}
	tcgetattr(0, &env->term);
	env->term.c_lflag &= ~(ICANON);
	env->term.c_lflag &= ~(ECHO);
	env->term.c_cc[VMIN] = 1;
	env->term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &env->term) == -1)
		exit (1);
	ft_putstr_fd(tgetstr("ti", NULL), 2);
	ft_putstr_fd(tgetstr("vi", NULL), 2);
}

static void			restart(int signum)
{
	t_environment	*env;

	(void)signum;
	env = get_set_environment(NULL);
	setup_terminal(env);
	set_signals(&restart);
	refresh_screen(0);
}

static void			setup_environment(t_environment *env, int argc, char **argv)
{
	env->words = argv + 1;
	env->word_count = argc - 1;
	env->highlighted_p = malloc((argc - 1) * sizeof(int));
	ft_bzero(env->highlighted_p, (argc - 1) * sizeof(int));
	env->current_word = 0;
	env->single_column_width = get_longest_word_length(env) + 2;
	setup_terminal(env);
}

int					main(int argc, char **argv)
{
	t_environment	*env;

	if (argc < 2)
		return (-1);
	env = malloc(sizeof(t_environment));
	setup_environment(env, argc, argv);
	get_set_environment(env);
	set_signals(&restart);
	refresh_screen(0);
	input_loop();
	return (0);
}
