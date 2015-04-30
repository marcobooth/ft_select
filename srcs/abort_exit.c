/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abort_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/30 13:24:10 by mbooth            #+#    #+#             */
/*   Updated: 2015/04/30 13:27:07 by mbooth           ###   ########.fr       */
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
