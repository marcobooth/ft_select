/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/27 18:21:19 by tfleming          #+#    #+#             */
/*   Updated: 2015/05/14 23:41:36 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
** called by signal ==> can't have env as argument
*/

static void			set_window_size(t_environment *env)
{
	struct winsize	window;

	ioctl(0, TIOCGWINSZ, &window);
	env->width = window.ws_col;
	env->height = window.ws_row;
}

static int			will_fit_on_screen(t_environment *env)
{
	int				number_of_columns;

	number_of_columns = env->word_count / env->height + 1;
	return ((number_of_columns * env->single_column_width) < env->width);
}

void				refresh_screen(int signum)
{
	t_environment	*env;

	(void)signum;
	env = get_set_environment(NULL);
	set_window_size(env);
	clear_screen_from_text(env);
	if (will_fit_on_screen(env))
		print_words(env);
	else
		ft_putstr_fd("Not enough room.", 2);
}
