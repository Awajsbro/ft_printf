/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_buff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 16:37:29 by awajsbro          #+#    #+#             */
/*   Updated: 2018/02/21 18:11:31 by awajsbro         ###   ########.fr       */
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

int ft_buff_exa(long long n, t_arg *arg, char cnt, int len)
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

int ft_buff_octa(long long n, t_arg *arg, char cnt, int len)
{
	char	s[len];
	char	out[cnt];

	s[len] = 0;
	if ((arg->flg & M_MINUS) != M_MINUS && arg->wth > 0)
		ft_fill(s, arg->wth, ' ', NULL);
	if ((arg->flg & M_DIEZE) == M_DIEZE)
		ft_fill(s, 1, '0', NULL);
	if (arg->acc > 0)
		ft_fill(s, arg->acc, '0', NULL);
	else if ((arg->flg & M_ZERO) == M_ZERO && arg->wth > 0)
		ft_fill(s, arg->wth, '0', NULL);
	ft_fill(s, cnt, 0, ft_itoab(n, 16, out));
	if ((arg->wth > 0 && (arg->flg & M_MINUS) == M_MINUS)
		&& ((arg->flg & M_ZERO) != M_ZERO || arg->acc > 0))
		ft_fill(s, arg->wth, ' ', NULL);
	ft_fill(s, 0, 0, NULL);
	return (len);
}

int ft_buff_deci(long long n, t_arg *arg, char cnt, int len)
{
	char	s[len];
	char	out[cnt];

	s[len] = 0;
	if ((arg->flg & M_MINUS) != M_MINUS && arg->wth > 0)
		ft_fill(s, arg->wth, ' ', NULL);
	if (n < 0)
		ft_fill(s, 1, '-', NULL);
	else if ((arg->flg & M_MORE) == M_MORE)
		ft_fill(s, 1, '+', NULL);
	if (arg->acc > 0)
		ft_fill(s, arg->acc, '0', NULL);
	else if ((arg->flg & M_ZERO) == M_ZERO && arg->wth > 0)
		ft_fill(s, arg->wth, '0', NULL);
	out = ft_itoab(n, 16, out);
	if (n < 0)
		ft_fill(s, cnt, 0, &out[1]));
	else
		ft_fill(s, cnt, 0, out);
	if ((arg->wth > 0 && (arg->flg & M_MINUS) == M_MINUS)
		&& ((arg->flg & M_ZERO) != M_ZERO || arg->acc > 0))
		ft_fill(s, arg->wth, ' ', NULL);
	ft_fill(s, 0, 0, NULL);
	return (len);
}

int ft_buff_bin(long long n, t_arg *arg, char cnt, int len)
{
	char	s[len];
	char	out[cnt];

	s[len] = 0;
	if ((arg->flg & M_MINUS) != M_MINUS && arg->wth > 0)
		ft_fill(s, arg->wth, ' ', NULL);
	if ((arg->flg & M_DIEZE) == M_DIEZE)
		ft_fill(s, 2, 0, "0b");
	if (arg->acc > 0)
		ft_fill(s, arg->acc, '0', NULL);
	else if ((arg->flg & M_ZERO) == M_ZERO && arg->wth > 0)
		ft_fill(s, arg->wth, '0', NULL);
	ft_fill(s, cnt, 0, ft_itoab(n, 16, out));
	if ((arg->wth > 0 && (arg->flg & M_MINUS) == M_MINUS)
		&& ((arg->flg & M_ZERO) != M_ZERO || arg->acc > 0))
		ft_fill(s, arg->wth, ' ', NULL);
		if (arg->spe == 'b')
		ft_fill(s, 0, 0, NULL);
	else
		ft_fill(s, 1, 0, NULL);
	return (len);
}
