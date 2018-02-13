/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 18:23:24 by awajsbro          #+#    #+#             */
/*   Updated: 2018/02/13 19:40:18 by awajsbro         ###   ########.fr       */
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

// static int ft_minnb(t_arg *arg, long long n)
// {
// 	int cnt;

// 	if (arg->spe == 'u' || arg->spe == 'd' ||arg->spe == 'i')
// 		cnt = arg->flg ft_cntb(n, 10);
// 	else if (arg->spe == 'p' || arg->spe == 'x')
// 		cnt = arg->flg == '#' ? ft_cntb(n, 16) + 2 : ft_cntb(n, 16);
// 	else
// 		cnt = arg->flg == '#' ? ft_cntb(n, 8) + 2 : ft_cntb(n, 8);

// }

// static int ft_majnb(t_arg arg, long long n)

// static int ft_science(t_arg arg, long long n)

// static int ft_str()

static int ft_exa_print(long long n, t_arg *arg)
{
	int cnt;

	cnt = ft_cntb(n, 16);
	cnt = arg->flg & M_DIEZE == M_DIEZE ? cnt + 2 : cnt;
	if (arg->flg & M_ZERO == M_ZERO)
	{

	}
	if (arg->acc != 0)
	{

	}
	if (arg->flg & M_MINUS == M_MINUS)
	{
		if (arg->spe == 'p' || arg->spe == 'x')
			write(1, "0x", 2);
		else
			write(1, "0X", 2);
	}
}

static int	ft_exapars(char *s, int i, va_list va, t_arg *arg)
{
	arg->flg == arg->acc != 0 ? arg->flg & M_
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
