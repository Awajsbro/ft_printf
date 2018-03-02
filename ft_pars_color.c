/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 19:19:32 by awajsbro          #+#    #+#             */
/*   Updated: 2018/03/02 13:17:45 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_etat(char const *s, int *i, t_col *col, char m)
{
	if (((ft_strnequ(&s[*i], "gras}", 5) == 1) && ((*(col->e) % 2) != 0))
		|| (m == 1 && ((*(col->e) % 2) == 0)))
	{
		ft_strcat(col->buff, "\033[1m");
		*(col->e) = (*(col->e) % 2 == 0) ? *(col->e) : *(col->e) * 2;
	}
	if (((ft_strnequ(&s[*i], "soul}", 5) == 1) && ((*(col->e) % 3) != 0))
		|| (m == 1 && ((*(col->e) % 3) == 0)))
	{
		ft_strcat(col->buff, "\033[4m");
		*(col->e) = (*(col->e) % 3 == 0) ? *(col->e) : *(col->e) * 3;
	}
	if (((ft_strnequ(&s[*i], "clig}", 5) == 1) && ((*(col->e) % 5) != 0))
		|| (m == 1 && ((*(col->e) % 5) == 0)))
	{
		ft_strcat(col->buff, "\033[5m");
		*(col->e) = (*(col->e) % 5 == 0) ? *(col->e) : *(col->e) * 5;
	}
	if (m == 0 && col->buff[0] == 0)
		*i = *i - 7;
	*i = m == 1 ? *i : (*i + 5);
}

static void	ft_printf_reset(char const *s, int *i, t_col *col)
{
	if (ft_strnequ(&s[*i], "true}", 5) == 1)
	{
		*(col->c) = 99;
		*(col->e) = 1;
	}
	else if (ft_strnequ(&s[*i], "back}", 5) == 1)
		*(col->c) = ((*(col->c) % 10) + 90);
	else if (ft_strnequ(&s[*i], "colo}", 5) == 1)
		*(col->c) = (((*(col->c) / 10) * 10) + 9);
	else if (ft_strnequ(&s[*i], "gras}", 5) == 1)
		*(col->e) = ((*(col->e) % 2) == 0) ? (*(col->e) / 2) : *(col->e);
	else if (ft_strnequ(&s[*i], "soul}", 5) == 1)
		*(col->e) = ((*(col->e) % 3) == 0) ? (*(col->e) / 3) : *(col->e);
	else if (ft_strnequ(&s[*i], "clig}", 5) == 1)
		*(col->e) = ((*(col->e) % 5) == 0) ? (*(col->e) / 5) : *(col->e);
	else
	{
		*i = *i - 7;
		return ;
	}
	ft_strcat(col->buff, "\033[0m");
	ft_printf_color(s, i, col, 1);
	ft_printf_back(s, i, col, 1);
	ft_printf_etat(s, i, col, 1);
	*i = *i + 5;
}

static void	ft_true_pars_color(char const *s, int *i, t_col *col)
{
	if (ft_strnequ(&s[*i], "{reset_", 7) == 1)
	{
		*i = *i + 7;
		ft_printf_reset(s, i, col);
	}
	else if (ft_strnequ(&s[*i], "{state_", 7) == 1)
	{
		*i = *i + 7;
		ft_printf_etat(s, i, col, 0);
	}
	else if (ft_strnequ(&s[*i], "{backgr_", 8) == 1)
	{
		*i = *i + 8;
		ft_printf_back(s, i, col, 0);
	}
	else
		ft_printf_color(s, i, col, 0);
}

char		ft_pars_color(char const *s, int *i, int fd)
{
	static t_col	col;
	static char		color = 99;
	static char		etat = 1;

	col.c = &color;
	col.e = &etat;
	ft_bzero(col.buff, 31);
	ft_true_pars_color(s, i, &col);
	ft_putstr_fd(col.buff, fd);
	return (0);
}
