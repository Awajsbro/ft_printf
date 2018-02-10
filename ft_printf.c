/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:55:44 by awajsbro          #+#    #+#             */
/*   Updated: 2018/02/10 20:04:05 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_minnb(t_arg *arg, long long n)
{
	int cnt;

	if (arg->spe == 'u' || arg->spe == 'd' ||arg->spe == 'i')
		cnt = arg->flg ft_cntb(n, 10);
	else if (arg->spe == 'p' || arg->spe == 'x')
		cnt = arg->flg == '#' ? ft_cntb(n, 16) + 2 : ft_cntb(n, 16);
	else
		cnt = arg->flg == '#' ? ft_cntb(n, 8) + 2 : ft_cntb(n, 8);

}

static int ft_majnb(t_arg arg, long long n)

static int ft_science(t_arg arg, long long n)

static int ft_str()

static char	ft_speci(char const *s, int *i)
{
	while (s[*i] == 'h' || s[*i] == 'l' || s[*i] == 'j' || s[*i] == 'z'
		|| s[*i] == 't' || s[*i] == 'L')
		(*i)++;
	(*i)++;
	return (s[*i - 1]);
}

static int	ft_initarg(char const *s, int *i, va_list va, t_arg *arg)
{
	arg->flg = 0;
	if (s[*i] == ' ' || s[*i] == '+' || s[*i] == '-'
		|| s[*i] == '#' || s[*i] == '0')
		arg->flg = s[*i];
	*i = arg->flg != 0 ? (*i + 1) : *i;
	arg->wth = s[*i] == '*' ? va_arg(va, int) : ft_atoi(&s[*i]);
	while (ft_isdigit(s[*i]) == 1 || s[*i] == '*')
		(*i)++;
	if (s[*i] == '.')
		arg->acc = s[++*i] == '*' ? va_arg(va, int) : ft_atoi(&s[*i]);
	while (ft_isdigit(s[*i]) == 1 || s[*i] == '*')
		(*i)++;
	arg->spe = ft_speci(s, i);
	if (argv->spe == 'p' )
		return(ft_exa(arg, (long long)va_arg(va, void*)));
	if (argv->spe == 'x')


}

static int	ft_pars(char const *s, int *i, va_list va, t_arg *arg)
{
	(*i)++;
	if (s[(*i)++] == '%')
		return (ft_putchar('%'));
	else if (s[--*i] == '{')
		return (ft_pars_color(s, i));

	else
		return (ft_initarg(s, i, va, arg));
}
int		ft_printf(char const *s, ...)
{
	va_list	va;
	t_arg	*arg;
	int		i;
	int		len;

	if (!(arg = (t_arg*)malloc(sizeof(*arg))))
		return (0);
	len = 0;
	va_start(va, s);
	while (s[0] != 0)
	{
		i = ft_strclen(s, '%');
		len = len + ft_putstrn(s, i);
		if (s[i] == '%')
			len = len + ft_pars(s, &i, va, arg);
		if (i == -42)
			break;
		s = s + i;
	}
	len = len < 0 ? -1 : len;
	free(arg);
	va_end(va);
	write(1, "\033[0m", 4);
	return (i == -42 ? -1 : len);
}

int			main(void)
{
	int		r;

	printf("%d\n", ft_printf("123||%%||%{rou}%{backgr_ble}%{reset_colo} -%%-\n"));
	return (0);
}
