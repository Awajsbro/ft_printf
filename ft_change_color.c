/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:01:27 by awajsbro          #+#    #+#             */
/*   Updated: 2018/03/02 14:36:32 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	ft_always_more_color(char const *s, int *i, t_col *col, char m)
{
	if (ft_strnequ(&s[*i], "{jau}", 5) == 1
		|| (m == 1 && (*(col->c) % 10 == 3)))
	{
		ft_strcat(col->buff, "\033[33m");
		*(col->c) = (((*(col->c) / 10) * 10) + 3);
	}
	else if (ft_strnequ(&s[*i], "{gri}", 5) == 1
		|| (m == 1 && (*(col->c) % 10 == 7)))
	{
		ft_strcat(col->buff, "\033[37m");
		*(col->c) = (((*(col->c) / 10) * 10) + 7);
	}
	else if (m == 0)
		return (0);
	*i = m == 1 ? *i : (*i + 5);
	return (0);
}

static char	ft_more_color(char const *s, int *i, t_col *col, char m)
{
	if (ft_strnequ(&s[*i], "{ble}", 5) == 1
		|| (m == 1 && (*(col->c) % 10 == 4)))
	{
		ft_strcat(col->buff, "\033[34m");
		*(col->c) = (((*(col->c) / 10) * 10) + 4);
	}
	else if (ft_strnequ(&s[*i], "{ros}", 5) == 1
		|| (m == 1 && (*(col->c) % 10 == 5)))
	{
		ft_strcat(col->buff, "\033[35m");
		*(col->c) = (((*(col->c) / 10) * 10) + 5);
	}
	else if (ft_strnequ(&s[*i], "{cya}", 5) == 1
		|| (m == 1 && (*(col->c) % 10 == 6)))
	{
		ft_strcat(col->buff, "\033[36m");
		*(col->c) = (((*(col->c) / 10) * 10) + 6);
	}
	else
		return (ft_always_more_color(s, i, col, m));
	*i = m == 1 ? *i : (*i + 5);
	return (0);
}

char		ft_printf_color(char const *s, int *i, t_col *col, char m)
{
	if (ft_strnequ(&s[*i], "{noi}", 5) == 1
		|| (m == 1 && (*(col->c) % 10 == 0)))
	{
		ft_strcat(col->buff, "\033[30m");
		*(col->c) = (((*(col->c) / 10) * 10) + 0);
	}
	else if (ft_strnequ(&s[*i], "{rou}", 5) == 1
		|| (m == 1 && (*(col->c) % 10 == 1)))
	{
		ft_strcat(col->buff, "\033[31m");
		*(col->c) = (((*(col->c) / 10) * 10) + 1);
	}
	else if (ft_strnequ(&s[*i], "{ver}", 5) == 1
		|| (m == 1 && (*(col->c) % 10 == 2)))
	{
		ft_strcat(col->buff, "\033[32m");
		*(col->c) = (((*(col->c) / 10) * 10) + 2);
	}
	else
		return (ft_more_color(s, i, col, m));
	*i = m == 1 ? *i : (*i + 5);
	return (0);
}
