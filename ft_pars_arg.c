/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 18:23:24 by awajsbro          #+#    #+#             */
/*   Updated: 2018/02/19 18:24:31 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define M_DIEZE		0x01
#define M_MINUS		0x02
#define M_MORE		0x04
#define M_SPACE		0x08
#define M_ZERO		0x10

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
	if (arg->spe == 'x' || arg->spe == 'X' || arg->spe == 'p')
		return (ft_exapars(s, i, va, arg));
	return (0);
}
