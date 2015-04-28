/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/27 13:39:07 by tfleming          #+#    #+#             */
/*   Updated: 2015/04/28 20:16:02 by mbooth           ###   ########.fr       */
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

# define KEY_ESCAPE 0x1b
# define KEY_SPACE 0x20
# define KEY_UP 0x415b1b
# define KEY_DOWN 0x425b1b
# define KEY_RIGHT 0x435b1b
# define KEY_LEFT 0x445b1b
# define KEY_ENTER 0xa
# define KEY_BACKSPACE 0x7f
# define KEY_DELETE 0x7e335b1b

typedef struct		s_environment
{
	int				width;
	int				height;
	char			**words;
	int				words_count;
	struct termios  term;
	int				*highlighted;
	int				current_argument;
}					t_environment;

int					main(int argc, char **argv);
void				print_words();
void				clear_screen_from_text(t_environment *env);
t_environment		*get_set_environment(t_environment *new_env);

#endif
