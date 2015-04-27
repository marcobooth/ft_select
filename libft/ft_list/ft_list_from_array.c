/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_from_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/10 16:41:28 by tfleming          #+#    #+#             */
/*   Updated: 2015/04/27 18:10:03 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list		*ft_list_from_array(int length, char **array)
{
	int			i;
	t_list		*first_elem;

	if (length == 0)
		return (NULL);
	i = 0;
	while (i < length)
	{
		ft_list_push_front(&first_elem, array[i]);
		i++;
	}
	ft_list_reverse(&first_elem);
	return (first_elem);
}
