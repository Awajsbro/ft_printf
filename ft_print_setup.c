/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_setup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 18:23:24 by awajsbro          #+#    #+#             */
/*   Updated: 2018/02/22 19:51:57 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

char	ft_define_fd(char *s, int *i, va_list va, t_arg *arg)
{
	if (ft_strnequ(&s[*i], "[fd", 3) == 1)
	{
		*i = *i + 4;
		if (s[*i - 1] == '*')
		{
			(*i)++;
			arg->fd = va_arg(va, int);
		}
		else
		{
			arg->fd = ft_atoi(&s[*i - 1]);
			while (ft_isdigit(s[*i - 1]) == 1)
				(*i)++;
		}
	}
	else if (ft_strnequ(&s[*i], "[\fd]", 4) == 1)
	{
		arg->fd = 1;
		*i = *i + 5;
	}
	return (0);
}
