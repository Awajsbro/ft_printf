/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_setup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 18:23:24 by awajsbro          #+#    #+#             */
/*   Updated: 2018/03/06 11:53:35 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_fill(char *s, char *s2, int len)
{
	static int	i = 0;

	if (len > 0)
	{
		len = len + i;
		while (i < len)
		{
			s[i] = s2[0];
			i++;
		}
	}
	else if (s2 != NULL)
	{
		ft_strcpy(&s[i], s2);
		i = i + ft_strlen(s2);
	}
	else
	{
		s[i] = 0;
		i = 0;
	}
	return (0);
}

char	ft_define_fd(char const *s, int *i, va_list va, t_arg *arg)
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
