/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/27 13:39:17 by tfleming          #+#    #+#             */
/*   Updated: 2015/04/29 20:03:45 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void				abort_exit(int signum)
{
	t_environment	*env;

	env = get_set_environment(NULL);
	clear_screen_from_text(env);
	(void)signum;
	ft_putstr(tgetstr("ve", NULL));
	ft_putstr(tgetstr("cl", NULL));
	exit (0);
}

static void			set_signals(void)
{
	signal(SIGWINCH, refresh_screen);
	signal(SIGCONT, restart);
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
	tgetent(NULL, terminal_name);
	tcgetattr(0, &env->term);
	env->term.c_lflag &= ~(ICANON);
	env->term.c_lflag &= ~(ECHO);
	env->term.c_cc[VMIN] = 1;
	env->term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &env->term) == -1)
		exit (1);
}

static void			setup_environment(t_environment *env, int argc, char **argv)
{
	env->words = argv + 1;
	env->word_count = argc - 1;
	env->highlighted_p = (int*)malloc(sizeof(int) * (argc - 1));
	ft_bzero(env->highlighted_p, argc - 1);
	env->current_word = 0;
	setup_terminal(env);
}

void				restart()
{
	t_environment	*env;

	env = get_set_environment(NULL);
	setup_terminal(env);
	set_signals();
	refresh_screen();
	input_loop();
}

int					main(int argc, char **argv)
{
	t_environment	*env;

	if (argc < 2)
		return (-1);
	env = malloc(sizeof(t_environment));
	setup_environment(env, argc, argv);
	get_set_environment(env);
	set_signals();
	ft_putstr(tgetstr("vi", NULL));
	refresh_screen();
	input_loop();
	return (0);
}
