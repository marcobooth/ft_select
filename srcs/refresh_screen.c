/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/27 18:21:19 by tfleming          #+#    #+#             */
/*   Updated: 2015/04/29 12:02:38 by tfleming         ###   ########.fr       */
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

static int			get_longest_word_length(t_environment *env)
{
	int				longest_word_length;
	int				current_length;
	int				i;

	longest_word_length = 0;
	i = 0;
	while (i < env->word_count)
	{
		current_length = ft_strlen((char*)env->words[i]);
		if (current_length > longest_word_length)
			longest_word_length = current_length;
		i++;
	}
	return (longest_word_length);
}

static int			will_fit_on_screen(t_environment *env
									, int single_column_width)
{
	int				number_of_columns;

	number_of_columns = env->word_count / env->height + 1;
	return ((number_of_columns * single_column_width) < env->width);
}

void				refresh_screen(void)
{
	t_environment	*env;
	int				single_column_width;

	env = get_set_environment(NULL);
	set_window_size(env);
	clear_screen_from_text(env);
	single_column_width = get_longest_word_length(env) + 2;
	if (will_fit_on_screen(env, single_column_width))
		print_words(env, single_column_width);
	else
		ft_putstr("Not enough room.");
}
