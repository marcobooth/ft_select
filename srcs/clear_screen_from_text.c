/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_screen_from_text.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 11:22:03 by tfleming          #+#    #+#             */
/*   Updated: 2015/04/28 11:56:20 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
** tgoto(tgetstr("cm", NULL), row, column)
** ==> moves cursor to (row, column)
**
** tgetstr("ce", NULL)
** ==> clears from where the cursor is to the end of that line
*/

static int		get_buffer_size(t_environment *env)
{
	int			cm_max_length;
	int			ce_max_length;

	cm_max_length = ft_strlen(tgoto(tgetstr("cm", NULL), 0, env->height - 1));
	ce_max_length = ft_strlen(tgetstr("ce", NULL));
	return ((cm_max_length + ce_max_length) * env->height);
}

void			clear_screen_from_text(t_environment *env)
{
	char			clear_screen_string[get_buffer_size(env)];
	char			*current_in_buffer;
	int				i;

	ft_printf("length = %d\n", get_buffer_size(env));
	current_in_buffer = (char*)clear_screen_string;
	i = 0;
	while (i < env->height)
	{
		ft_printf("i = %d\n", i);
		ft_printf("current place = %zu\n"
					, current_in_buffer - clear_screen_string);
		tgoto(tgetstr("cm", &current_in_buffer), 0, i);
		tgetstr("ce", &current_in_buffer);
		i++;
	}
	ft_putstr(clear_screen_string);
}
