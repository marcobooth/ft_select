/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set_environment.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 11:53:24 by mbooth            #+#    #+#             */
/*   Updated: 2016/01/05 11:53:26 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
** hack to store the environment somewhere (globals are not allowed)
** if argument is non-NULL, sets env
** always returns the current env
*/

t_environment		*get_set_environment(t_environment *new_env)
{
	static t_environment	*stored_env = NULL;

	if (new_env)
		stored_env = new_env;
	return (stored_env);
}
