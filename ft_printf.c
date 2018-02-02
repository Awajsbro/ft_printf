/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:55:44 by awajsbro          #+#    #+#             */
/*   Updated: 2018/02/02 19:51:47 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
static char	*ft_wip(char const *s, int *i, char *str, va_list va)
{
	*i = *i + 1;
	if (s[*i] == 'c')
		return (ft_memset(ft_strnew(1), (va_arg(va, int) % 256), 1));
	else if (s[*i] == 'i' || s[*i] == 'd')
		return (ft_joinfree(ft_strndup(s, *i - 1), ft_itoa(va_arg(va, int))));
	return (ft_memalloc(0));
}

static char	*ft_pars(char const *s,int *i, char *str, va_list va)
{
	if (s[*i] == 0)
		return (ft_strdup(s));
	return (ft_wip(s, i , str, va));
}
//
//static char	*ft_color(char const *s, int *i, char *str)
//{
//	static char gras;
//	static char
//}
//
int			ft_printf(char const *s, ...)
{
	va_list	va;
	int		i;
	char	*str;

	va_start(va, s);
	i = 0;
	str = ft_strnew(0);
	while (s[i] != 0)
	{
		while (!(s[i] == '%' && s[i + 1] != '%') && s[i] != 0 && s[i] != '{')
			i++;
		if (s[i] == '{')
//			str = ft_color(s, &i, str);
;
		else
			str = ft_joinfree(str, ft_pars(s, &i, str, va));
		if (i == -42)
			break;
		s = s[i] != 0 ? s + i + 1 : s + i;
		i = 0;
	}
	va_end(va);
	ft_putstr(str);
	return (i == -42 ? ft_strlen(str) : -1);
}
*/

static size_t	ft_initarg(char *s, int *i, va_list)
{
	char		flg;
	size_t		wth;
	size_t		acc;
	char		lgh[2];
	int			j;

	j = *i;
	flg = 0;
	wth = 0;
	acc = 0;
	if (s[j] == 32 || s[j] == '+' || s[j] == '-' || s[j] == '#' || s[j] == '0')
		flg = s[j];
	j = flg != 0 ? j++ : j;
	wth = s[j] == '*' ? va_arg(va, int) : ft_atoi(&s[j]);
	while (ft_isalpha(s[j]) == 0 || s[j] == '.')
		j++;
	acc = s[j] == '*' ? va_arg(va, int) : ft_atoi(&s[j]);

}

static size_t	ft_pars(char const *s, int *i, va_list va)
{
	*i = *i + 1;
	if (s[*i] == '%')
	{
		*i = *i + 1;
		return (ft_putstr("%"));
	}
	else if (s[*i] == '{')
		return (ft_pars_color(s, i));
	else if (ft_strnequ(s[*i], "file", 4) == 1)
		return (print_fd(s, i, va));
	else
		return (ft_initarg(s, i, va));
}

int		ft_printf(char const *s, ...)
{
	va_list		va;
	int			i;
	long long	len;

	len = 0;
	va_start(va, s);
	while (s[0] != 0)
	{
		i = ft_strclen(s, '%');
		len = len + ft_putstrn(s, i);
		if (s[i] == '%')
			len = len + ft_pars(s, &i, va);
		if (i == -42)
			break;
		s = s + i;
	}
	va_end(va);
	return (i == -42 ? -1 : len);
}

int			main(void)
{
	int		r;

	r = ft_printf("123||%d||abc -%c-\n", 2147483647, 310);
	printf("%c\n", 310);
//	ft_putnbr(r);
	return (0);
}
