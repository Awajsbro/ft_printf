/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 19:19:32 by awajsbro          #+#    #+#             */
/*   Updated: 2018/02/22 14:12:03 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_etat(char const *s, int *i, char *e, char m)
{
	if (((ft_strnequ(&s[*i], "gras}", 5) == 1) && ((*e % 2) != 0))
		|| (m == 1 && ((*e % 2) == 0)))
	{
		write(1, "\033[1m", 4);
		*e = (*e % 2 == 0) ? *e : *e * 2;
	}
	if (((ft_strnequ(&s[*i], "soul}", 5) == 1) && ((*e % 3) != 0))
		|| (m == 1 && ((*e % 3) == 0)))
	{
		write(1, "\033[4m", 4);
		*e = (*e % 3 == 0) ? *e : *e * 3;
	}
	if (((ft_strnequ(&s[*i], "clig}", 5) == 1) && ((*e % 5) != 0))
		|| (m == 1 && ((*e % 5) == 0)))
	{
		write(1, "\033[5m", 4);
		*e = (*e % 5 == 0) ? *e : *e * 5;
	}
	*i = m == 1 ? *i : (*i + 5);
}

static void	ft_printf_reset(char const *s, int *i, char *c, char *e)
{
	write(1, "\033[0m", 4);
	if (ft_strnequ(&s[*i], "true}", 5) == 1)
	{
		*c = 99;
		*e = 1;
	}
	else if (ft_strnequ(&s[*i], "back}", 5) == 1)
		*c = ((*c % 10) + 90);
	else if (ft_strnequ(&s[*i], "colo}", 5) == 1)
		*c = (((*c / 10) * 10) + 9);
	else if (ft_strnequ(&s[*i], "gras}", 5) == 1)
		*e = ((*e % 2) == 0) ? (*e / 2) : *e;
	else if (ft_strnequ(&s[*i], "soul}", 5) == 1)
		*e = ((*e % 3) == 0) ? (*e / 3) : *e;
	else if (ft_strnequ(&s[*i], "clig}", 5) == 1)
		*e = ((*e % 5) == 0) ? (*e / 5) : *e;
	ft_printf_color(s, i, c, 1);
	ft_printf_back(s, i, c, 1);
	ft_printf_etat(s, i, e, 1);
	*i = *i + 5;
}

char		ft_pars_color(char const *s, int *i)
{
	static	char	color = 99;
	static	char	etat = 1;

	if (ft_strnequ(&s[*i], "{reset_", 7) == 1)
	{
		*i = *i + 7;
		ft_printf_reset(s, i, &color, &etat);
	}
	else if (ft_strnequ(&s[*i], "{state_", 7) == 1)
	{
		*i = *i + 7;
		ft_printf_etat(s, i, &etat, 0);
	}
	else if (ft_strnequ(&s[*i], "{backgr_", 8) == 1)
	{
		*i = *i + 8;
		ft_printf_back(s, i, &color, 0);
	}
	else
		ft_printf_color(s, i, &color, 0);
	return (0);
}
