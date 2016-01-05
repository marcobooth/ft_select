/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_nth_from_array.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 11:56:16 by mbooth            #+#    #+#             */
/*   Updated: 2016/01/05 11:56:20 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** width is the sizeof() for the things in the array
*/

#include "libft.h"

void				ft_remove_nth_from_array(int nth, void *array
												, size_t width, int length)
{
	char			*to_remove;

	to_remove = (((char*)array) + nth * width);
	ft_memmove((void*)to_remove, (void*)(to_remove + width)
				, (length - nth - 1) * width);
}
