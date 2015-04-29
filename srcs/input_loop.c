/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 10:51:00 by tfleming          #+#    #+#             */
/*   Updated: 2015/04/29 19:15:27 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
** input_loop waits for keypresses on call to read()
*/

static void			select_deselect(t_environment *env)
{
	if (env->highlighted_p[env->current_word] == 1)
		env->highlighted_p[env->current_word] = 0;
	else
		env->highlighted_p[env->current_word] = 1;
	env->current_word = (env->current_word == env->word_count - 1
								? 0 : env->current_word + 1);
}

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

static void			remove_selected(t_environment *env)
{
	int				bleh;

	bleh = 1;
	ft_remove_nth_from_array(env->current_word, (void*)env->words
								, sizeof(char*), env->word_count);
	ft_remove_nth_from_array(env->current_word, (void*)env->highlighted_p
								, sizeof(int), env->word_count);
	env->word_count--;
	normalize_current_word(env);
	if (env->word_count <= 0)
		exit(0);
}

void				input_loop()
{
	unsigned long	keycode;
	t_environment   *env;
	int				should_refresh;

	env = get_set_environment(NULL);
	while (keycode = 0, (read(0, &keycode, 6)) != 0)
	{
		should_refresh = 1;
		if (keycode == KEY_BACKSPACE || keycode == KEY_DELETE)
			remove_selected(env);
		else if (keycode == KEY_SPACE)
			select_deselect(env);
		else if (keycode == KEY_ENTER)
			return_highlighted_words(env);
		else if (keycode == KEY_DOWN || keycode == KEY_UP
				 || keycode == KEY_LEFT || keycode == KEY_RIGHT)
			handle_arrow_key(env, keycode);
		else if (keycode == KEY_ESCAPE)
			abort_exit(0);
		else
			should_refresh = 0;
		if (should_refresh)
			refresh_screen();
	}
}
