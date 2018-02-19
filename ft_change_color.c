/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:01:27 by awajsbro          #+#    #+#             */
/*   Updated: 2018/02/19 17:01:29 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	ft_more_back(char const *s, int *i, char *c, char m)
{
	if (ft_strnequ(&s[*i], "ble}", 4) == 1 || (m == 1 && (*c / 10 == 4)))
	{
		write(1, "\033[44m", 5);
		*c = ((*c % 10) + 40);
	}
	else if (ft_strnequ(&s[*i], "ros}", 4) == 1 || (m == 1 && (*c / 10 == 5)))
	{
		write(1, "\033[35m", 5);
		*c = ((*c % 10) + 50);
	}
	else if (ft_strnequ(&s[*i], "cya}", 4) == 1 || (m == 1 && (*c / 10 == 6)))
	{
		write(1, "\033[36m", 5);
		*c = ((*c % 10) + 60);
	}
	else if (ft_strnequ(&s[*i], "gri}", 4) == 1 || (m == 1 && (*c / 10 == 7)))
	{
		write(1, "\033[37m", 5);
		*c = ((*c % 10) + 70);
	}
	*i = m == 1 ? *i : (*i + 4);
	return (0);
}

char		ft_printf_back(char const *s, int *i, char *c, char m)
{
	if (ft_strnequ(&s[*i], "noi}", 4) == 1 || (m == 1 && (*c / 10 == 0)))
	{
		write(1, "\033[30m", 5);
		*c = ((*c % 10) + 0);
	}
	else if (ft_strnequ(&s[*i], "rou}", 4) == 1 || (m == 1 && (*c / 10 == 1)))
	{
		write(1, "\033[31m", 5);
		*c = ((*c % 10) + 10);
	}
	else if (ft_strnequ(&s[*i], "ver}", 4) == 1 || (m == 1 && (*c / 10 == 2)))
	{
		write(1, "\033[32m", 5);
		*c = ((*c % 10) + 20);
	}
	else if (ft_strnequ(&s[*i], "jau}", 4) == 1 || (m == 1 && (*c / 10 == 3)))
	{
		write(1, "\033[33m", 5);
		*c = ((*c % 10) + 30);
	}
	else
		return (ft_more_back(s, i, c, m));
	*i = m == 1 ? *i : (*i + 4);
	return (0);
}

static char	ft_more_color(char const *s, int *i, char *c, char m)
{
	if (ft_strnequ(&s[*i], "{ble}", 5) == 1 || (m == 1 && (*c % 10 == 4)))
	{
		write(1, "\033[34m", 5);
		*c = (((*c / 10) * 10) + 4);
	}
	else if (ft_strnequ(&s[*i], "{ros}", 5) == 1 || (m == 1 && (*c % 10 == 5)))
	{
		write(1, "\033[35m", 5);
		*c = (((*c / 10) * 10) + 5);
	}
	else if (ft_strnequ(&s[*i], "{cya}", 5) == 1 || (m == 1 && (*c % 10 == 6)))
	{
		write(1, "\033[36m", 5);
		*c = (((*c / 10) * 10) + 6);
	}
	else if (ft_strnequ(&s[*i], "{gri}", 5) == 1 || (m == 1 && (*c % 10 == 7)))
	{
		write(1, "\033[37m", 5);
		*c = (((*c / 10) * 10) + 7);
	}
	*i = m == 1 ? *i : (*i + 5);
	return (0);
}

char		ft_printf_color(char const *s, int *i, char *c, char m)
{
	if (ft_strnequ(&s[*i], "{noi}", 5) == 1 || (m == 1 && (*c % 10 == 0)))
	{
		write(1, "\033[30m", 5);
		*c = (((*c / 10) * 10) + 0);
	}
	else if (ft_strnequ(&s[*i], "{rou}", 5) == 1 || (m == 1 && (*c % 10 == 1)))
	{
		write(1, "\033[31m", 5);
		*c = (((*c / 10) * 10) + 1);
	}
	else if (ft_strnequ(&s[*i], "{ver}", 5) == 1 || (m == 1 && (*c % 10 == 2)))
	{
		write(1, "\033[32m", 5);
		*c = (((*c / 10) * 10) + 2);
	}
	else if (ft_strnequ(&s[*i], "{jau}", 5) == 1 || (m == 1 && (*c % 10 == 3)))
	{
		write(1, "\033[33m", 5);
		*c = (((*c / 10) * 10) + 3);
	}
	else
		return (ft_more_color(s, i, c, m));
	*i = m == 1 ? *i : (*i + 5);
	return (0);
}
