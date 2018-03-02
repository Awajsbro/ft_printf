/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 13:19:50 by awajsbro          #+#    #+#             */
/*   Updated: 2018/03/02 14:38:15 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	ft_always_more_back(char const *s, int *i, t_col *col, char m)
{
	if (ft_strnequ(&s[*i], "jau}", 4) == 1
		|| (m == 1 && (*(col->c) / 10 == 3)))
	{
		ft_strcat(col->buff, "\033[33m");
		*(col->c) = ((*(col->c) % 10) + 30);
	}
	else if (ft_strnequ(&s[*i], "gri}", 4) == 1
		|| (m == 1 && (*(col->c) / 10 == 7)))
	{
		ft_strcat(col->buff, "\033[37m");
		*(col->c) = ((*(col->c) % 10) + 70);
	}
	else if (m == 0)
	{
		*i = *i - 12;
		return (0);
	}
	*i = m == 1 ? *i : (*i + 4);
	return (0);
}

static char	ft_more_back(char const *s, int *i, t_col *col, char m)
{
	if (ft_strnequ(&s[*i], "ble}", 4) == 1 || (m == 1 && (*(col->c) / 10 == 4)))
	{
		ft_strcat(col->buff, "\033[44m");
		*(col->c) = ((*(col->c) % 10) + 40);
	}
	else if (ft_strnequ(&s[*i], "ros}", 4) == 1
		|| (m == 1 && (*(col->c) / 10 == 5)))
	{
		ft_strcat(col->buff, "\033[35m");
		*(col->c) = ((*(col->c) % 10) + 50);
	}
	else if (ft_strnequ(&s[*i], "cya}", 4) == 1
		|| (m == 1 && (*(col->c) / 10 == 6)))
	{
		ft_strcat(col->buff, "\033[36m");
		*(col->c) = ((*(col->c) % 10) + 60);
	}
	else
		return (ft_always_more_back(s, i, col, m));
	*i = m == 1 ? *i : (*i + 4);
	return (0);
}

char		ft_printf_back(char const *s, int *i, t_col *col, char m)
{
	if (ft_strnequ(&s[*i], "noi}", 4) == 1 || (m == 1 && (*(col->c) / 10 == 0)))
	{
		ft_strcat(col->buff, "\033[30m");
		*(col->c) = ((*(col->c) % 10) + 0);
	}
	else if (ft_strnequ(&s[*i], "rou}", 4) == 1
		|| (m == 1 && (*(col->c) / 10 == 1)))
	{
		ft_strcat(col->buff, "\033[31m");
		*(col->c) = ((*(col->c) % 10) + 10);
	}
	else if (ft_strnequ(&s[*i], "ver}", 4) == 1
		|| (m == 1 && (*(col->c) / 10 == 2)))
	{
		ft_strcat(col->buff, "\033[32m");
		*(col->c) = ((*(col->c) % 10) + 20);
	}
	else
		return (ft_more_back(s, i, col, m));
	*i = m == 1 ? *i : (*i + 4);
	return (0);
}
