/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:55:44 by awajsbro          #+#    #+#             */
/*   Updated: 2018/01/26 19:13:19 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_wip(char *s, int *i, char *str, va_list va)
{
	*i = *i + 1;
	if (s[*i] == 'c')
		return (ft_memset(ft_strnew(1), va_arg(va, int), 1));
	else if (s[*i] == 'i' || s[*i] == 'd')
		return (ft_joinfree(ft_strndup(s, *i - 1), ft_itoa(va_arg(va, int))));
	return ("");
}

static char	*pars(s, *i, str, va)
{
	if (s[i] == 0)
		return (ft_strdup(s));
	*i = *i + 1;
	if (s[*i] == '%')
		return (ft_memset(ft_strnew(1), '%', 1));

}

int			ft_printf(char constq *s, ...)
{
	va_list	va;
	int		i;
	char	*str;

	va_start(va, s);
	i = 0;
	str = ft_strnew(0);
	while (s[i] != 0)
	{
		while (!(s[i] == '%' && s[i + 1] != '%') && s[i] != 0)
			i++;
		str = ft_joinfree(str, ft_pars(s, &i, str, va));
		s = s + i;
		i = 0;
	}
	va_end(va);
	ft_putstr(str);
	len = len >= 0 ? ft_strlen(str) : -1;
	return (len);
}

int			main(void)
{
	int		r;

	r = ft_printf("%d\n", 2147483648);
	printf("%d%c", 3, 'a');
//	ft_putnbr(r);
	return (0);
}
