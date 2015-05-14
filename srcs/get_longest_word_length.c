/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_longest_word_length.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 23:32:16 by tfleming          #+#    #+#             */
/*   Updated: 2015/05/14 23:35:10 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			get_longest_word_length(t_environment *env)
{
	int				longest_word_length;
	int				current_length;
	int				i;

	longest_word_length = 0;
	i = 0;
	while (i < env->word_count)
	{
		current_length = ft_strlen((char*)env->words[i]);
		if (current_length > longest_word_length)
			longest_word_length = current_length;
		i++;
	}
	return (longest_word_length);
}
