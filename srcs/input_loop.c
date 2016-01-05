/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 11:53:35 by mbooth            #+#    #+#             */
/*   Updated: 2016/01/05 11:53:37 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** input_loop waits for keypresses on call to read
*/

#include "ft_select.h"

static void			select_deselect(t_environment *env)
{
	if (env->highlighted_p[env->current_word] == 1)
		env->highlighted_p[env->current_word] = 0;
	else
		env->highlighted_p[env->current_word] = 1;
	env->current_word = (env->current_word == env->word_count - 1
								? 0 : env->current_word + 1);
}

static void			handle_up_down(t_environment *env, int keycode)
{
	if (keycode == KEY_DOWN)
	{
		env->current_word++;
		if (env->current_word > env->word_count - 1)
			env->current_word = 0;
	}
	else if (keycode == KEY_UP)
	{
		env->current_word--;
		if (env->current_word < 0)
			env->current_word = env->word_count - 1;
	}
}

static void			handle_left_right(t_environment *env, int keycode)
{
	int				new_current_word;
	int				position_from_top;

	position_from_top = env->current_word % env->height;
	if (keycode == KEY_LEFT)
	{
		new_current_word = env->current_word - env->height;
		if (new_current_word < 0)
			env->current_word = new_current_word
			+ (env->word_count / env->height) * env->height
			+ (position_from_top < env->height
				- env->word_count % env->height) * env->height;
		else
			env->current_word = new_current_word;
		if (env->current_word >= env->word_count)
			env->current_word -= env->height;
	}
	else if (keycode == KEY_RIGHT)
	{
		new_current_word = env->current_word + env->height;
		if (new_current_word >= env->word_count)
			env->current_word = position_from_top;
		else
			env->current_word = new_current_word;
	}
}

static void			remove_selected(t_environment *env)
{
	ft_remove_nth_from_array(env->current_word, (void*)env->words
								, sizeof(char*), env->word_count);
	ft_remove_nth_from_array(env->current_word, (void*)env->highlighted_p
								, sizeof(int), env->word_count);
	env->word_count--;
	if (env->word_count <= 0)
		abort_exit(0);
	if (env->current_word >= env->word_count)
		env->current_word = 0;
}

void				input_loop(void)
{
	unsigned long	keycode;
	t_environment	*env;

	env = get_set_environment(NULL);
	keycode = 0;
	while (read(0, &keycode, 6) != 0)
	{
		if (keycode == KEY_BACKSPACE || keycode == KEY_DELETE)
			remove_selected(env);
		else if (keycode == KEY_SPACE)
			select_deselect(env);
		else if (keycode == KEY_ENTER)
			return_highlighted_words(env);
		else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
			handle_left_right(env, keycode);
		else if (keycode == KEY_DOWN || keycode == KEY_UP)
			handle_up_down(env, keycode);
		else if (keycode == KEY_ESCAPE || keycode == 'q')
			abort_exit(0);
		else
			continue;
		refresh_screen(0);
		keycode = 0;
	}
}
