/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/27 18:21:19 by tfleming          #+#    #+#             */
/*   Updated: 2015/04/28 21:32:01 by mbooth           ###   ########.fr       */
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
		ft_putstr(tgoto(tgetstr("cm", NULL), 0, row)); // what is this for?
		ft_putstr(tgetstr("ce", NULL));
		column = 0;
		while (((current = (env->height * column) + row))
											< env->words_count)
		{
			if (env->highlighted[current] == 1)
				ft_putstr(tgetstr("so", NULL));
			if (env->current_argument == current)
				ft_putstr(tgetstr("us", NULL));
			ft_putstr(env->words[current]);
			if (env->current_argument == current)
				ft_putstr(tgetstr("ue", NULL));
		  if (env->highlighted[current] == 1)
			  ft_putstr(tgetstr("se", NULL));
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

	env = get_set_environment(NULL);
	set_window_size(env);
	clear_screen_from_text(env);
	single_width = get_longest_word_length(env) + 2;
	if (will_fit_on_screen(env, single_width))
		actually_print(env, single_width);
	else
		ft_putstr("Not enough room.");
}
