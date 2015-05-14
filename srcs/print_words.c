/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 10:58:12 by tfleming          #+#    #+#             */
/*   Updated: 2015/05/14 23:42:44 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
** assumes screen has already been cleared (in refresh_screen.c)
** cm: position the cursor at line l, column c
** ce: clear from the cursor to the end of the current line
** so: enter standout mode
** se: leave standout mode
** us: turn on underline mode or to output a magic cookie to start
**     underlining
** ue: turn off underline mode or to output a magic cookie to stop
**     underlining
*/

static void			turn_on_special_text(t_environment *env, int current)
{
	if (env->highlighted_p[current] == 1)
		ft_putstr_fd(tgetstr("so", NULL), 2);
	if (env->current_word == current)
		ft_putstr_fd(tgetstr("us", NULL), 2);
}

static void			turn_off_special_text(t_environment *env, int current)
{
	if (env->current_word == current)
		ft_putstr_fd(tgetstr("ue", NULL), 2);
	if (env->highlighted_p[current] == 1)
		ft_putstr_fd(tgetstr("se", NULL), 2);
}

void				print_words(t_environment *env)
{
	int				row;
	int				column;
	int				current;

	row = 0;
	while (row < env->height && row < env->word_count)
	{
		ft_putstr_fd(tgoto(tgetstr("cm", NULL), 0, row), 2);
		ft_putstr_fd(tgetstr("ce", NULL), 2);
		column = 0;
		while (((current = (env->height * column) + row)) < env->word_count)
		{
			turn_on_special_text(env, current);
			ft_putstr_fd(env->words[current], 2);
			turn_off_special_text(env, current);
			ft_putcharn_fd(' ', env->single_column_width
							- ft_strlen(env->words[current]), 2);
			column++;
		}
		row++;
	}
}
