/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_nth_from_array.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 14:28:16 by mbooth            #+#    #+#             */
/*   Updated: 2015/04/28 15:30:25 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// change header

#include "libft.h"

void				ft_remove_nth_from_array(int nth, void **array, int *length)
{
	ft_memmove((void*)(array + nth), (void*)(array + nth + 1)
				, (*length - nth - 1) * sizeof(void*));
	(*length)--;
}
