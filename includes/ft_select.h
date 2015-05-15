/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/27 13:39:07 by tfleming          #+#    #+#             */
/*   Updated: 2015/05/15 20:39:04 by tfleming         ###   ########.fr       */
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
** term.h :: tgetent, tgetstr, etc.
** ioctl.h :: ioctl
*/

# include "libft.h"
# include "ft_list.h"
# include "ft_printf.h"
# include <termios.h>
# include <term.h>
# include <sys/ioctl.h>

# define KEY_ESCAPE 0x1B
# define KEY_SPACE 0x20
# define KEY_UP 0x415B1B
# define KEY_DOWN 0x425B1B
# define KEY_RIGHT 0x435B1B
# define KEY_LEFT 0x445B1B
# define KEY_ENTER 0xA
# define KEY_BACKSPACE 0x7F
# define KEY_DELETE 0x7E335B1B

/*
** width, height: size of terminal currently
** words: the strings
** words_count: number of strings
** highlighted_p: is highlighted_p[x] = if words[x] is highlighted
** current_argument: where the cursor is
** term: terminal stuff (bleh)
*/

typedef struct		s_environment
{
	int				width;
	int				height;
	char			**words;
	int				word_count;
	int				*highlighted_p;
	int				current_word;
	int				single_column_width;
	struct termios	term;
}					t_environment;

int					main(int argc, char **argv);
void				input_loop(void);
void				refresh_screen(int signum);
void				clear_screen_from_text(t_environment *env);
int					get_longest_word_length(t_environment *env);
void				print_words(t_environment *env);
void				return_highlighted_words(t_environment *env);
void				abort_no_exit(int signum);
void				abort_exit(int signum);

/*
** hack to store the environment somewhere (globals are not allowed)
** if argument is non-NULL, sets env
** always returns the current env
*/

t_environment		*get_set_environment(t_environment *new_env);

#endif
