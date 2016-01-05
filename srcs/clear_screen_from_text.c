/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_screen_from_text.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 11:53:09 by mbooth            #+#    #+#             */
/*   Updated: 2016/01/05 11:53:12 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** tgoto(tgetstr("cm", NULL), row, column)
** ==> moves cursor to (row, column)
** tgetstr("ce", NULL)
** ==> clears from where the cursor is to the end of that line
*/

#include "ft_select.h"

void			clear_screen_from_text(t_environment *env)
{
	int				i;

	i = 0;
	while (i < env->height)
	{
		ft_putstr_fd(tgoto(tgetstr("cm", NULL), 0, i), 2);
		ft_putstr_fd(tgetstr("ce", NULL), 2);
		i++;
	}
}
