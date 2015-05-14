/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abort_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 17:57:19 by tfleming          #+#    #+#             */
/*   Updated: 2015/05/14 23:47:11 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
** ve: return the cursor to normal
** cl: clear the entire screen and position the cursor at the upper
** left corner
** te: undo what is done by the `ti' string. Programs that output the
** ti: string on entry should output this string when they exit
*/

void				abort_no_exit(int signum)
{
	t_environment	*env;
	char			copy[2];

	(void)signum;
	env = get_set_environment(NULL);
	clear_screen_from_text(env);
	env->term.c_lflag |= (ICANON | ECHO);
	tcsetattr(0, 0, &(env->term));
	ft_putstr_fd(tgetstr("te", NULL), 2);
	ft_putstr_fd(tgetstr("ve", NULL), 2);
	if (signum == SIGTSTP)
	{
		signal(SIGTSTP, SIG_DFL);
		copy[0] = env->term.c_cc[VSUSP];
		copy[1] = 0;
		ioctl(0, TIOCSTI, copy);
	}
}

void				abort_exit(int signum)
{
	abort_no_exit(signum);
	exit (0);
}
