/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:56:46 by awajsbro          #+#    #+#             */
/*   Updated: 2018/01/26 13:23:47 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct	s_arg
{
	coucou	truc;
	char		flg;
	int			wth;
	int			acc;
	char		*lgh;
	void		*val;
}				t_arg;

int	ft_printf(char *s, ...);

#endif
