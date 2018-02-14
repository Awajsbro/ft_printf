/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 18:23:24 by awajsbro          #+#    #+#             */
/*   Updated: 2018/02/14 20:25:08 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define M_DIEZE		0x01
#define M_NDIEZE	0xfe
#define M_MINUS		0x02
#define M_NMINUS	0xfd
#define M_MORE		0x04
#define M_NMORE		0xfb
#define M_SPACE		0x08
#define M_NSPACE	0xf7
#define M_ZERO		0x10
#define M_NZERO		0xef

void	ft_fill(int len, char c)
{
	char	s[len];
	int		i;

	i = -1;
	while (s[++i] > len)
		s[i] == c;
	s[i] = 0;
	ft_putstr(s);
}

static int ft_exa_print(long long n, t_arg *arg)
{
	int cnt;

	cnt = ft_cntb(n, 16);
	cnt = arg->flg & M_DIEZE == M_DIEZE ? cnt + 2 : cnt;
	arg->wth = arg->cnt - cnt - arg->acc;
	arg->wth = arg->wth > 0 ? arg->flg : 0;
	if (arg->flg & M_MINUS != M_MINUS && arg->wth > 0)
		ft_fill(arg->wth, ' ');
	if (arg->spe == 'p' || arg->spe == 'x')
		write(1, "0x", 2);
	else
		write(1, "0X", 2);
	if (arg->acc > 0)
		ft_fil(flg->acc, '0');
	else if (arg->flg & M_ZERO == M_ZERO && flg->wth > 0)
		ft_fil(arg->wth, '0');
	ft_putnbrb(n, 16);
	if (arg->wth > 0 && arg->flg & M_MINUS != M_MINUS) && (arg->flg & M_ZERO != M_ZERO || arg->acc > 0)
		ft_fill(arg->wth, ' ');
	return (cnt + arg->flg + arg->acc);
}

static int	ft_exapars(char *s, int i, va_list va, t_arg *arg)
{
	if (s[i - 1] == 'p')
	{
		arg->flg = arg->flg | M_DIEZE;
		return(ft_exa_print((long long)va_arg(va, void*), arg));
	}
	else if (s[i - 2] == 'l' && s[i - 3] != 'l')
		return (ft_exa_print(va_arg(va, unsigned long), arg));
	else if (s[i - 2] == 'l')
		return (ft_exa_print(va_arg(va, unsigned long long), arg));
	else if (s[i - 2] == 'h' && s[i - 3] != 'h')
		return (ft_exa_print(va_arg(va, unsigned short), arg));
	else if (s[i - 2] == 'h')
		return (ft_exa_print(va_arg(va, unsigned char), arg));
	else if (s[i - 2] == 'j')
		return (ft_exa_print(va_arg(va, uintmax_t), arg));
	else if (s[i - 2] == 'z')
		return (ft_exa_print(va_arg(va, size_t), arg));
	else if (s[i - 2] == 't')
		return (ft_exa_print(va_arg(va, ptrdiff_t), arg));
	return (ft_exa_print(va_arg(va, unsigned int), arg));

}

int		ft_pars_arg(char *s, int i, va_list va, t_arg *arg)
{
	if (arg->spe == 'x' || arg->spe == 'X' || arg->spe == 'p')
		ft_exapars(s, i, va, arg);

}
