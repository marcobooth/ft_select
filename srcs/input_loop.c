/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 10:51:00 by tfleming          #+#    #+#             */
/*   Updated: 2015/04/29 12:18:48 by tfleming         ###   ########.fr       */
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

static void			print_selected(t_environment *env)
{
	int				i;
	int				print_space_p;

	print_space_p = 0;
	i = 0;
	while (i < env->word_count)
	{
		if (env->highlighted_p[i])
		{
			if (print_space_p)
				ft_putchar(' ');
			ft_putstr(env->words[i]);
			print_space_p = 1;
		}
	}
}

static void			remove_selected(t_environment *env)
{
	int				bleh;

	bleh = 1;
	ft_remove_nth_from_array(env->current_word, (void**)env->words
								, sizeof(char*), &env->word_count);
	ft_remove_nth_from_array(env->current_word, (void**)env->highlighted_p
								, sizeof(int), &bleh);
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
		if (keycode == KEY_BACKSPACE)
			remove_selected(env);
		else if (keycode == KEY_SPACE)
			select_deselect(env);
		else if (keycode == KEY_ENTER)
			print_selected(env);
		else if (keycode == KEY_DOWN || keycode == KEY_UP
				 || keycode == KEY_LEFT || keycode == KEY_RIGHT)
			handle_arrow_key(env, keycode);
		else
			should_refresh = 0;
		if (should_refresh)
			refresh_screen();
	}
}
