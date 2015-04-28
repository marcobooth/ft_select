/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/27 18:21:19 by tfleming          #+#    #+#             */
/*   Updated: 2015/04/28 11:53:43 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
** note about actually_print: row starts at 1
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
	while (i < env->words_count)
	{
		current_length = ft_strlen((char*)env->words[i]);
		if (current_length > longest_word_length)
			longest_word_length = current_length;
		i++;
	}
	return (longest_word_length);
}

static int			will_fit_on_screen(t_environment *env
									   , int single_width)
{
	int				number_of_columns;

	ft_printf("env width, height = %d, %d\n", env->width, env->height);
	number_of_columns = env->words_count / env->height + 1;
	return ((number_of_columns * single_width) < env->width);
}

static void			actually_print(t_environment *env
								     , int single_width)
{
	int				row;
	int				column;
	int				current;

	row = 0;
	while (row < env->height && row < env->words_count)
	{
		if (row != 0)
			ft_putstr("\n");
		column = 0;
		while (((current = (env->height * column) + row))
											< env->words_count)
		{
			ft_putstr(env->words[current]);
			ft_putcharn(' ', single_width
								- ft_strlen(env->words[current]));
			column++;
		}
		row++;
	}
	(void)single_width;
}

void				print_words()
{
	t_environment	*env;
	int				single_width;

	ft_printf("beginning of print_words\n");
	env = get_set_environment(NULL);
	set_window_size(env);
	ft_printf("before clearing from screen\n");
	clear_screen_from_text(env);
	ft_printf("after clearing from screen\n");
	single_width = get_longest_word_length(env) + 2;
	ft_printf("before actually printing\n");
	if (will_fit_on_screen(env, single_width))
		actually_print(env, single_width);
	else
		ft_putstr("Not enough room.");
}
