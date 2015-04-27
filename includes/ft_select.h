/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/27 13:39:07 by tfleming          #+#    #+#             */
/*   Updated: 2015/04/27 17:40:55 by tfleming         ###   ########.fr       */
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
# include <termios.h>
# include <term.h>
# include <sys/ioctl.h>

typedef struct		s_environment
{
	int				column_width;
	int				column_height;
	
}					t_environment;

int					main(int argc, char **argv);

#endif
