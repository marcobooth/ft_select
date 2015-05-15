/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set_environment.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/27 20:53:23 by tfleming          #+#    #+#             */
/*   Updated: 2015/05/15 20:39:05 by tfleming         ###   ########.fr       */
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
