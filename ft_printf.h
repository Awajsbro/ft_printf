/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:56:46 by awajsbro          #+#    #+#             */
/*   Updated: 2018/02/10 14:24:16 by awajsbro         ###   ########.fr       */
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
	char		spe;
}				t_arg;

int				ft_printf(char const *s, ...);
char			ft_pars_color(char const *s, int *i);
char			ft_printf_color(char const *s, int *i, char *c, char m);
char			ft_printf_back(char const *s, int *i, char *c, char m);

/*
** {state_gras}	 =	\033[01m --	active le gras
** {state_soul}	 =	\033[04m --	active le souligner
** {state_clig}	 =	\033[05m --	active le clignotement
** {noi}		 =	\033[30m --	change la couleur en noir
** {rou}		 =	\033[31m --	change la couleur en rouge
** {ver}		 =	\033[32m --	change la couleur en vert
** {jau}		 =	\033[33m --	change la couleur en jaune
** {ble}		 =	\033[34m --	change la couleur en bleu
** {ros}		 =	\033[35m --	change la couleur en rose
** {cya}		 =	\033[36m --	change la couleur en cyan
** {gri}		 =	\033[37m --	change la couleur en gris
** {backgr_noi}	 =	\033[40m --	change le fond en noir
** {backgr_rou}	 =	\033[41m --	change le fond en rouge
** {backgr_ver}	 =	\033[42m --	change le fond en vert
** {backgr_jau}	 =	\033[43m --	change le fond en jaune
** {backgr_ble}	 =	\033[44m --	change le fond en bleu
** {backgr_ros}	 =	\033[45m --	change le fond en rose
** {backgr_cya}	 =	\033[46m --	change le fond en cyan
** {backgr_gri}	 =	\033[47m --	change le fond en gris
** {reset_true}	 =	\033[00m --	retire tous le changement
** {reset_back}				 -- remet le fond vanilla
** {reset_colo}				 --	remet la couleur vanilla
** {reset_gras}				 -- retire le gras
** {reset_soul}				 --	retire le soulignage
** {reset_clig}				 --	retire le clignotant
** {reset_stat}				 --	retire tous les etat gras souligner et clignotant
**
** file...					 --	lit (...) lignes d'un fichiers
** file*					 --	lit (valeur du parametre apres le fd) lignes d'un ficher
*/

#endif
