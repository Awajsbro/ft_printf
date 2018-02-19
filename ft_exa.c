/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 18:20:54 by awajsbro          #+#    #+#             */
/*   Updated: 2018/02/19 18:25:36 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define M_DIEZE		0x01
#define M_MINUS		0x02
#define M_MORE		0x04
#define M_SPACE		0x08
#define M_ZERO		0x10

static int ft_buff_exa(long long n, t_arg *arg, char cnt, int len)
{
	char	s[len];
	char	out[cnt];

	s[len] = 0;
	if ((arg->flg & M_MINUS) != M_MINUS && arg->wth > 0)
		ft_fill(s, arg->wth, ' ', NULL);
	if ((arg->flg & M_DIEZE) == M_DIEZE)
		ft_fill(s, 2, 0, "0x");
	if (arg->acc > 0)
		ft_fill(s, arg->acc, '0', NULL);
	else if ((arg->flg & M_ZERO) == M_ZERO && arg->wth > 0)
		ft_fill(s, arg->wth, '0', NULL);
	ft_fill(s, cnt, 0, ft_itoab(n, 16, out));
	if ((arg->wth > 0 && (arg->flg & M_MINUS) == M_MINUS)
		&& ((arg->flg & M_ZERO) != M_ZERO || arg->acc > 0))
		ft_fill(s, arg->wth, ' ', NULL);
	if (arg->spe != 'X')
		ft_fill(s, 0, 0, NULL);
	else
		ft_fill(s, 1, 0, NULL);
	return (len);
}

static int ft_exa_cnt(long long n, t_arg *arg)
{
	char cnt;

	cnt = ft_cntb(n, 16);
	arg->acc = arg->acc > cnt ? arg->acc - cnt : 0;
	cnt = (arg->flg & M_DIEZE) == M_DIEZE ? cnt + 2 : cnt;
	arg->wth = arg->wth - cnt - arg->acc;
	arg->wth = arg->wth > 0 ? arg->wth : 0;
	return (ft_buff_exa(n, arg, cnt, (cnt + arg->acc + arg->wth)));
}

int			ft_exapars(char const *s, int i, va_list va, t_arg *arg)
{
	if (s[i - 1] == 'p')
	{
		arg->flg = (arg->flg | M_DIEZE);
		return(ft_exa_cnt((long long)va_arg(va, void*), arg));
	}
	else if (s[i - 2] == 'l' && s[i - 3] != 'l')
		return (ft_exa_cnt(va_arg(va, unsigned long), arg));
	else if (s[i - 2] == 'l')
		return (ft_exa_cnt(va_arg(va, unsigned long long), arg));
	else if (s[i - 2] == 'h' && s[i - 3] != 'h')
		return (ft_exa_cnt((unsigned short)va_arg(va, int), arg));
	else if (s[i - 2] == 'h')
		return (ft_exa_cnt((unsigned char)va_arg(va, int), arg));
	else if (s[i - 2] == 'j')
		return (ft_exa_cnt(va_arg(va, uintmax_t), arg));
	else if (s[i - 2] == 'z')
		return (ft_exa_cnt(va_arg(va, size_t), arg));
	else if (s[i - 2] == 't')
		return (ft_exa_cnt(va_arg(va, ptrdiff_t), arg));
    return (ft_exa_cnt(va_arg(va, unsigned int), arg));

}
