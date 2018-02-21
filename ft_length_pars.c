/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length_pars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 18:27:43 by awajsbro          #+#    #+#             */
/*   Updated: 2018/02/21 18:07:17 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define M_DIEZE		0x01
#define M_NDIEZE 	0xfe
#define M_MINUS		0x02
#define M_NMINUS	0xfd
#define M_MORE		0x04
#define M_NMORE		0xfb
#define M_SPACE		0x08
#define M_NSPACE	0xf7
#define M_ZERO		0x10
#define M_NZERO		0xef

static int ft_unsigned_cnt(long long n, t_arg *arg)
{
	char cnt;

	if (arg->spe == 'p' || arg->spe == 'x' || arg->spe == 'X')
		arg->bas = 16;
	else if (arg->spe == 'o' || arg->spe == 'O')
		arg->bas = 8;
	else if (arg->spe == 'u' || arg->spe == 'U')
		arg->bas = 10;
	else if (arg->spe == 'b' || arg->spe == 'B')
		arg->bas = 2;
	cnt = ft_cntb(n, arg->bas);
	arg->acc = arg->acc > cnt ? arg->acc - cnt : 0;
	cnt = (arg->flg & M_DIEZE) == M_DIEZE ? cnt + 2 : cnt;
	arg->wth = arg->wth - cnt - arg->acc;
	arg->wth = arg->wth > 0 ? arg->wth : 0;
	if (arg->bas == 16)
		return (ft_buff_exa(n, arg, cnt, (cnt + arg->acc + arg->wth)));
	else if (arg->bas == 10)
		return (ft_buff_deci(n, arg, cnt, (cnt + arg->acc + arg->wth)));
	else if (arg->bas == 8)
		return (ft_buff_octa(n, arg, cnt, (cnt + arg->acc + arg->wth)));
	else if (arg->bas == 2)
		return (ft_buff_bin(n, arg, cnt, (cnt + arg->acc + arg->wth)));
	return (0);
}

int			ft_unsigned_pars(char const *s, int i, va_list va, t_arg *arg)
{
	arg->flg = (arg->flg & M_NMORE);
	if (s[i - 1] == 'p')
	{
		arg->flg = (arg->flg | M_DIEZE);
		return(ft_unisgned_cnt((long long)va_arg(va, void*), arg));
	}
	else if (s[i - 2] == 'l' && s[i - 3] == 'l')
		return (ft_unsigned_cnt(va_arg(va, unsigned long long), arg));
	else if (s[i - 2] == 'l' || arg->spe == 'O' || arg->spe == 'U')
		return (ft_unsigned_cnt(va_arg(va, unsigned long), arg));
	else if (s[i - 2] == 'h' && s[i - 3] != 'h')
		return (ft_unsigned_cnt((unsigned short)va_arg(va, int), arg));
	else if (s[i - 2] == 'h')
		return (ft_unsigned_cnt((unsigned char)va_arg(va, int), arg));
	else if (s[i - 2] == 'j')
		return (ft_unsigned_cnt(va_arg(va, uintmax_t), arg));
	else if (s[i - 2] == 'z')
		return (ft_unsigned_cnt(va_arg(va, size_t), arg));
	else if (s[i - 2] == 't')
		return (ft_unsigned_cnt(va_arg(va, ptrdiff_t), arg));
    return (ft_unsigned_cnt(va_arg(va, unsigned int), arg));
}

static int ft_signed_cnt(long long n, t_arg *arg)
{
	char cnt;

	arg->bas = 10;
	cnt = ft_cntb(n, arg->bas);
	arg->acc = arg->acc > cnt ? arg->acc - cnt : 0;
	if (n < 0)
		cnt++;
	else if ((arg->flg & M_MORE) == M_MORE)
		cnt++;
	arg->wth = arg->wth - cnt - arg->acc;
	arg->wth = arg->wth > 0 ? arg->wth : 0;
	return (ft_buff_deci(n, arg, cnt, (cnt + arg->acc + arg->wth)));
}

int			ft_signed_pars(char const *s, int i, va_list va, t_arg *arg)
{
	if (s[i - 2] == 'l' && s[i - 3] == 'l')
		return (ft_signed_cnt(va_arg(va, long long), arg));
	else if (s[i - 2] == 'l' || arg->spe == 'D')
		return (ft_signed_cnt(va_arg(va, long), arg));
	else if (s[i - 2] == 'h' && s[i - 3] != 'h')
		return (ft_signed_cnt((short)va_arg(va, int), arg));
	else if (s[i - 2] == 'h')
		return (ft_signed_cnt((signed char)va_arg(va, int), arg));
	else if (s[i - 2] == 'j')
		return (ft_signed_cnt(va_arg(va, intmax_t), arg));
	else if (s[i - 2] == 'z')
		return (ft_signed_cnt(va_arg(va, size_t), arg));
	else if (s[i - 2] == 't')
		return (ft_signed_cnt(va_arg(va, ptrdiff_t), arg));
    return (ft_signed_cnt(va_arg(va, int), arg));
}
