/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:56:46 by awajsbro          #+#    #+#             */
/*   Updated: 2018/02/02 18:40:47 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct	s_arg
{
	char		flg;
	size_t		wth;
	size_t		acc;
	char		*lgh;
}				t_arg;

int				ft_printf(char const *s, ...);
size_t			ft_pars_color(char const *s, int *i);
size_t			ft_printf_color(char const *s, int *i, char *c, char m);
size_t			ft_printf_back(char const *s, int *i, char *c, char m);
size_t			print_fd(char const s, int *i, va_list va);

/*
** {state_gras}	 =	\033[01m --
** {state_soul}	 =	\033[04m --
** {state_clig}	 =	\033[05m --
** {noi}		 =	\033[30m --
** {rou}		 =	\033[31m --
** {ver}		 =	\033[32m --
** {jau}		 =	\033[33m --
** {ble}		 =	\033[34m --
** {ros}		 =	\033[35m --
** {cya}		 =	\033[36m --
** {gri}		 =	\033[37m --
** {backgr_noi}	 =	\033[40m --
** {backgr_rou}	 =	\033[41m --
** {backgr_ver}	 =	\033[42m --
** {backgr_jau}	 =	\033[43m --
** {backgr_ble}	 =	\033[44m --
** {backgr_ros}	 =	\033[45m --
** {backgr_cya}	 =	\033[46m --
** {backgr_gri}	 =	\033[47m --
** {reset_true}	 =	\033[00m --
** {reset_back}				 --
** {reset_colo}				 --
** {reset_gras}				 --
** {reset_soul}				 --
** {reset_clig}				 --
** {reset_stat}				 --
*/

#endif
