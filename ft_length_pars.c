/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length_pars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 18:27:43 by awajsbro          #+#    #+#             */
/*   Updated: 2018/03/20 17:11:21 by awajsbro         ###   ########.fr       */
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
#define PF_LEN_NONE	0
#define PF_LEN_HH	1
#define PF_LEN_H	2
#define PF_LEN_Z	3
#define PF_LEN_T	4
#define PF_LEN_J	5
#define PF_LEN_L	6
#define PF_LEN_LL	7

static int	ft_more_unsigned_cnt(t_ull n, char cnt, t_arg *arg)
{
	int		len;

	arg->wth = arg->acc > 0 ? arg->wth - cnt - arg->acc : arg->wth - cnt;
	arg->wth = arg->wth > 0 ? arg->wth : 0;
	len = arg->acc > 0 ? arg->wth + cnt + arg->acc : arg->wth + cnt;
	if (arg->base == 16)
		return (ft_buff_exa(n, arg, cnt, len));
	else if (arg->base == 10)
		return (ft_buff_udeci(n, arg, cnt, len));
	else if (arg->base == 8)
		return (ft_buff_octa(n, arg, cnt, len));
	else if (arg->base == 2)
		return (ft_buff_bin(n, arg, cnt, len));
	return (0);
}

static int	ft_unsigned_cnt(t_ull n, t_arg *arg)
{
	char	cnt;

	if (arg->spe == 'p' || arg->spe == 'x' || arg->spe == 'X')
		arg->base = 16;
	else if (arg->spe == 'o' || arg->spe == 'O')
		arg->base = 8;
	else if (arg->spe == 'u' || arg->spe == 'U')
		arg->base = 10;
	else if (arg->spe == 'b' || arg->spe == 'B')
		arg->base = 2;
	cnt = (n == 0 && arg->acc == 0) ? 0 : ft_ucntb(n, arg->base);
	if (arg->acc != 0)
		arg->acc = arg->acc > cnt ? arg->acc - cnt : -1;
	if ((arg->base == 16 || arg->base == 8 || arg->base == 2)
			&& ((M_DIEZE & arg->flg) == M_DIEZE) && (n != 0 || arg->spe == 'p'))
		cnt = arg->base == 8 ? cnt + 1 : cnt + 2;
	return (ft_more_unsigned_cnt(n, cnt, arg));
}

int			ft_unsigned_pars(va_list va, t_arg *arg)
{
	if ((arg->flg & M_MINUS) == M_MINUS || (arg->acc > -1))
		arg->flg = (arg->flg & M_NZERO);
	arg->flg = (arg->flg & M_NMORE);
	if (arg->spe == 'p')
	{
		arg->flg = (arg->flg | M_DIEZE);
		return (ft_unsigned_cnt((long long)va_arg(va, void*), arg));
	}
	else if (arg->len == PF_LEN_LL)
		return (ft_unsigned_cnt(va_arg(va, t_ull), arg));
	else if (arg->len == PF_LEN_L || arg->spe == 'O' || arg->spe == 'U')
		return (ft_unsigned_cnt(va_arg(va, unsigned long), arg));
	else if (arg->len == PF_LEN_H)
		return (ft_unsigned_cnt((unsigned short)va_arg(va, int), arg));
	else if (arg->len == PF_LEN_HH)
		return (ft_unsigned_cnt((unsigned char)va_arg(va, int), arg));
	else if (arg->len == PF_LEN_J)
		return (ft_unsigned_cnt(va_arg(va, uintmax_t), arg));
	else if (arg->len == PF_LEN_Z)
		return (ft_unsigned_cnt(va_arg(va, size_t), arg));
	else if (arg->len == PF_LEN_T)
		return (ft_unsigned_cnt(va_arg(va, ptrdiff_t), arg));
	return (ft_unsigned_cnt(va_arg(va, unsigned int), arg));
}

static int	ft_signed_cnt(long long n, t_arg *arg)
{
	char	cnt;
	int		len;

	arg->base = 10;
	cnt = (n == 0 && arg->acc == 0) ? 0 : ft_cntb(n, arg->base);
	if (arg->acc != 0)
		arg->acc = arg->acc > cnt ? arg->acc - cnt : -1;
	if (n < 0)
	{
		cnt++;
		arg->flg = (M_NSPACE & arg->flg);
	}
	else if ((arg->flg & M_MORE) == M_MORE)
		cnt++;
	arg->wth = arg->acc > 0 ? arg->wth - cnt - arg->acc : arg->wth - cnt;
	arg->wth = arg->wth < 1 && (M_SPACE & arg->flg) == M_SPACE ? 1 : arg->wth;
	len = arg->acc > 0 ? arg->wth + cnt + arg->acc : arg->wth + cnt;
	return (ft_buff_deci(n, arg, cnt, len));
}

int			ft_signed_pars(va_list va, t_arg *arg)
{
	if ((arg->flg & M_MINUS) == M_MINUS || (arg->acc > -1))
		arg->flg = (arg->flg & M_NZERO);
	if (arg->len == PF_LEN_LL)
		return (ft_signed_cnt(va_arg(va, long long), arg));
	else if (arg->len == PF_LEN_L || arg->spe == 'D')
		return (ft_signed_cnt(va_arg(va, long), arg));
	else if (arg->len == PF_LEN_H)
		return (ft_signed_cnt((short)va_arg(va, int), arg));
	else if (arg->len == PF_LEN_HH)
		return (ft_signed_cnt((signed char)va_arg(va, int), arg));
	else if (arg->len == PF_LEN_J)
		return (ft_signed_cnt(va_arg(va, intmax_t), arg));
	else if (arg->len == PF_LEN_Z)
		return (ft_signed_cnt(va_arg(va, size_t), arg));
	else if (arg->len == PF_LEN_T)
		return (ft_signed_cnt(va_arg(va, ptrdiff_t), arg));
	return (ft_signed_cnt(va_arg(va, int), arg));
}
