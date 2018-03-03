/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_buff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 16:37:29 by awajsbro          #+#    #+#             */
/*   Updated: 2018/03/03 17:05:57 by awajsbro         ###   ########.fr       */
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

int	ft_buff_exa(t_ull n, t_arg *arg, char cnt, int len)
{
	char	buff[len + 1];
	char	out[cnt + 1];

	if ((arg->flg & M_MINUS) != M_MINUS && arg->wth > 0
		&& (arg->acc > 0 || (arg->flg & M_ZERO) != M_ZERO))
		ft_fill(buff, " ", arg->wth, arg->fd);
	if ((arg->flg & M_DIEZE) == M_DIEZE && n != 0)
		ft_fill(buff, "0x", 0, arg->fd);
	if (arg->acc > 0)
		ft_fill(buff, "0", arg->acc, arg->fd);
	else if ((arg->flg & M_ZERO) == M_ZERO && arg->wth > 0)
		ft_fill(buff, "0", arg->wth, arg->fd);
	ft_fill(buff, ft_uitoab(n, 16, out), 0, arg->fd);
	if ((arg->wth > 0 && (arg->flg & M_MINUS) == M_MINUS)
		&& ((arg->flg & M_ZERO) != M_ZERO || arg->acc > 0))
		ft_fill(buff, " ", arg->wth, arg->fd);
	if (arg->spe != 'X')
		return (ft_fill(buff, NULL, 0, arg->fd));
	else
		return (ft_fill(buff, NULL, -1, arg->fd));
}

int	ft_buff_octa(t_ull n, t_arg *arg, char cnt, int len)
{
	char	buff[len + 1];
	char	out[cnt + 1];

	if ((arg->flg & M_MINUS) != M_MINUS && arg->wth > 0
		&& (arg->acc > 0 || (arg->flg & M_ZERO) != M_ZERO))
		ft_fill(buff, " ", arg->wth, arg->fd);
	if ((arg->flg & M_DIEZE) == M_DIEZE && n != 0)
		ft_fill(buff, "0", 1, arg->fd);
	if (arg->acc > 0)
		ft_fill(buff, "0", arg->acc, arg->fd);
	else if ((arg->flg & M_ZERO) == M_ZERO && arg->wth > 0)
		ft_fill(buff, "0", arg->wth, arg->fd);
	ft_fill(buff, ft_uitoab(n, 8, out), 0, arg->fd);
	if ((arg->wth > 0 && (arg->flg & M_MINUS) == M_MINUS)
		&& ((arg->flg & M_ZERO) != M_ZERO || arg->acc > 0))
		ft_fill(buff, " ", arg->wth, arg->fd);
	return (ft_fill(buff, NULL, 0, arg->fd));
}

int	ft_buff_udeci(t_ull n, t_arg *arg, char cnt, int len)
{
	char	buff[len + 1];
	char	out[cnt + 1];

	if ((arg->flg & M_MINUS) != M_MINUS && arg->wth > 0
		&& (arg->acc > 0 || (arg->flg & M_ZERO) != M_ZERO))
		ft_fill(buff, " ", arg->wth, arg->fd);
	if (arg->acc > 0)
		ft_fill(buff, "0", arg->acc, arg->fd);
	else if ((arg->flg & M_ZERO) == M_ZERO && arg->wth > 0)
		ft_fill(buff, "0", arg->wth, arg->fd);
	ft_fill(buff, ft_itoab(n, 10, out), 0, arg->fd);
	if ((arg->wth > 0 && (arg->flg & M_MINUS) == M_MINUS)
		&& ((arg->flg & M_ZERO) != M_ZERO || arg->acc > 0))
		ft_fill(buff, " ", arg->wth, arg->fd);
	return (ft_fill(buff, NULL, 0, arg->fd));
}

int	ft_buff_bin(t_ull n, t_arg *arg, char cnt, int len)
{
	char	buff[len + 1];
	char	out[cnt + 1];

	if ((arg->flg & M_MINUS) != M_MINUS && arg->wth > 0
		&& (arg->acc > 0 || (arg->flg & M_ZERO) != M_ZERO))
		ft_fill(buff, " ", arg->wth, arg->fd);
	if ((arg->flg & M_DIEZE) == M_DIEZE && n != 0)
		ft_fill(buff, "0b", 0, arg->fd);
	if (arg->acc > 0)
		ft_fill(buff, "0", arg->acc, arg->fd);
	else if ((arg->flg & M_ZERO) == M_ZERO && arg->wth > 0)
		ft_fill(buff, "0", arg->wth, arg->fd);
	ft_fill(buff, ft_uitoab(n, 2, out), 0, arg->fd);
	if ((arg->wth > 0 && (arg->flg & M_MINUS) == M_MINUS)
		&& ((arg->flg & M_ZERO) != M_ZERO || arg->acc > 0))
		ft_fill(buff, " ", arg->wth, arg->fd);
	if (arg->spe == 'b')
		return (ft_fill(buff, NULL, 0, arg->fd));
	else
		return (ft_fill(buff, NULL, -1, arg->fd));
}
