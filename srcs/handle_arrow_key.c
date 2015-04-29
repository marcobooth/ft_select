/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arrow_key.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 12:06:35 by tfleming          #+#    #+#             */
/*   Updated: 2015/04/29 12:12:34 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void			normalize_current_word(t_environment *env)
{
	if (env->current_word > env->word_count - 1)
		env->current_word = 0;
	if (env->current_word < 0)
		env->current_word = env->word_count - 1;
}

void				handle_arrow_key(t_environment *env, int keycode)
{
	// TODO: handle right and left keys, make it loop correctly up and down
	if (keycode == KEY_DOWN)
		env->current_word++;
	else if (keycode == KEY_UP)
		env->current_word--;
	normalize_current_word(env);
}
