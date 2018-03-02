/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signed_buff.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 16:36:44 by awajsbro          #+#    #+#             */
/*   Updated: 2018/02/28 16:49:56 by awajsbro         ###   ########.fr       */
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

int	ft_buff_deci(long long n, t_arg *arg, char cnt, int len)
{
	char	buff[len + 1];
	char	out[cnt + 1];

	if ((arg->flg & M_MINUS) != M_MINUS && arg->wth > 0
		&& (arg->acc > 0 || (arg->flg & M_ZERO) != M_ZERO))
		ft_fill(buff, " ", arg->wth, arg->fd);
	if (n < 0)
		ft_fill(buff, "-", 1, arg->fd);
	else if ((arg->flg & M_MORE) == M_MORE)
		ft_fill(buff, "+", 1, arg->fd);
	if (arg->acc > 0)
		ft_fill(buff, "0", arg->acc, arg->fd);
	else if ((arg->flg & M_ZERO) == M_ZERO && arg->wth > 0)
		ft_fill(buff, "0", arg->wth, arg->fd);
	ft_itoab(n, 10, out);
	if (n < 0)
		ft_fill(buff, &out[1], 0, arg->fd);
	else
		ft_fill(buff, out, 0, arg->fd);
	if ((arg->wth > 0 && (arg->flg & M_MINUS) == M_MINUS)
		&& ((arg->flg & M_ZERO) != M_ZERO || arg->acc > 0))
		ft_fill(buff, " ", arg->wth, arg->fd);
	ft_fill(buff, NULL, 0, arg->fd);
	return (len);
}
