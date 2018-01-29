/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:56:46 by awajsbro          #+#    #+#             */
/*   Updated: 2018/01/29 19:08:39 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct	s_arg
{
	char		flg;
	int			wth;
	int			acc;
	char		*lgh;
	void		*val;
}				t_arg;

int	ft_printf(char const *s, ...);

/*
** {\state_gras} =	\033[01m
** {\state_soul} =	\033[04m
** {\state_clig} =	\033[05m
** {\noir}		 =	\033[30m --
** {\rouge}		 =	\033[31m
** {\vert}		 =	\033[32m --
** {\jaune}		 =	\033[33m
** {\bleu}		 =	\033[34m --
** {\rose}		 =	\033[35m --
** {\cyan}		 =	\033[36m
** {\gris}		 =	\033[37m
** {\fond_blanc} =	\033[07m
** {\fond_noir}	 =	\033[40m
** {\fond_rouge} =	\033[41m
** {\fond_vert}	 =	\033[42m
** {\fond_jaune} =	\033[43m
** {\fond_bleu}	 =	\033[44m
** {\fond_rose}	 =	\033[45m
** {\fond_cyan}	 =	\033[46m
** {\fond_gris}	 =	\033[47m
** {\reset_true} =	\033[00m
** {\reset_fond}
** {\reset_colo}
** {\reset_gras}
** {\reset_soul}
** {\reset_clig}
*/

#endif
