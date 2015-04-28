/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/27 13:39:07 by tfleming          #+#    #+#             */
/*   Updated: 2015/04/28 11:49:21 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

/*
** Allowed functions:
** isatty
** ttyname
** ttyslot
** ioctl (gets struct winsize, column width and column height)
** getenv
** tcsetattr
** tcgetattr
** tgetent (do this before doing the other t* commands -- sets the TERM)
** tgetflag
** tgetnum
** tgetstr (gets string to do termcaps command)
** tgoto
** tputs
** open
** close
** write
** malloc
** free
** read
** exit
** signal
*/

/*
** termios.h :: tc[get/set]attr
** term.h :: tgetent, tgetstr
** ioctl.h :: ioctl
*/

# include "libft.h"
# include "ft_list.h"
# include "ft_printf.h"
# include <termios.h>
# include <term.h>
# include <sys/ioctl.h>

typedef struct		s_environment
{
	int				width;
	int				height;
	char			**words;
	int				words_count;
}					t_environment;

int					main(int argc, char **argv);
void				print_words();
void				clear_screen_from_text(t_environment *env);
t_environment		*get_set_environment(t_environment *new_env);

#endif
