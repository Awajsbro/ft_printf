/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 18:23:24 by awajsbro          #+#    #+#             */
/*   Updated: 2018/02/21 18:07:22 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define M_DIEZE		0x01
#define M_NDIEZE 	0xfe
#define M_MINUS		0x02
#define M_NMINUS	0xfd
#define M_MORE		0x04
#define M_NMORE		0xfb
#define M_SPACE		0x08
#define M_NSPACE	0xf7
#define M_ZERO		0x10
#define M_NZERO		0xef

void	ft_fill(char *s, int len, char c, char *s2)
{
	static int	i = 0;

	if (c != 0)
	{
		len = len + i;
		while (i <  len)
		{
			s[i] = c;
			i++;
		}
	}
	else if (s2 != NULL)
	{
		s = ft_strcpy(&s[i], s2);
		i = i + ft_strlen(s2);
	}
	else
	{
		i = 0;
		if (len == 0)
			ft_putstr(s);
		else
			ft_putstr(ft_strupper(s));
	}
}

int		ft_pars_arg(char const *s, int i, va_list va, t_arg *arg)
{
	if (arg->spe == 'x' || arg->spe == 'X' || arg->spe == 'p'
		|| arg->spe == 'U' || arg->spe == 'u' || arg->spe == 'o' || arg-> 'O')
		return (ft_unsigned_pars(s, i, va, arg));
	else if (arg->spe == 'd' || arg->spe == 'D' || arg->spe == 'i')
		return (ft_signed_pars(s, i, va, arg));
	return (ft_putchar(arg->spe));
}
