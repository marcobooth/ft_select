/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 10:58:12 by tfleming          #+#    #+#             */
/*   Updated: 2015/04/29 12:10:26 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
** assumes screen has already been cleared (in refresh_screen.c)
*/

static void			output_string(t_environment *env, int current)
{
	if (env->highlighted_p[current] == 1)
		ft_putstr(tgetstr("so", NULL));
	if (env->current_word == current)
		ft_putstr(tgetstr("us", NULL));
	ft_putstr(env->words[current]);
	if (env->current_word == current)
		ft_putstr(tgetstr("ue", NULL));
	if (env->highlighted_p[current] == 1)
		ft_putstr(tgetstr("se", NULL));
}

void				print_words(t_environment *env, int single_column_width)
{
	int				row;
	int				column;
	int				current;

	row = 0;
	while (row < env->height && row < env->word_count)
	{
		ft_putstr(tgoto(tgetstr("cm", NULL), 0, row));
		ft_putstr(tgetstr("ce", NULL));
		column = 0;
		while (((current = (env->height * column) + row)) < env->word_count)
		{
			output_string(env, current);
			ft_putcharn(' ', single_column_width
								- ft_strlen(env->words[current]));
			column++;
		}
		row++;
	}
	(void)single_column_width;
}
