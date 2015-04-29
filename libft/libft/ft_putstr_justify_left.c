/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_justify_left.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/27 20:20:52 by tfleming          #+#    #+#             */
/*   Updated: 2015/04/29 15:42:00 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_putstr_justify_left(char *string
											, size_t total
											, char fill)
{
	size_t			length;
	size_t			i;

	ft_putstr(string);
	length = ft_strlen(string);
	i = 0;
	while (i + length < total)
	{
		ft_putchar(fill);
		i++;
	}
}
