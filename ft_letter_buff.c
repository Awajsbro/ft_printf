/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_letter_buff.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 17:04:25 by awajsbro          #+#    #+#             */
/*   Updated: 2018/03/02 14:39:12 by awajsbro         ###   ########.fr       */
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

static int	ft_letter_buff(char *s, t_arg *arg, int len)
{
	char	buff[len + 1];

	if ((arg->flg & M_MINUS) != M_MINUS && arg->wth > 0)
	{
		if ((arg->flg & M_ZERO) != M_ZERO)
			ft_fill(buff, " ", arg->wth, arg->fd);
		else
			ft_fill(buff, "0", arg->wth, arg->fd);
	}
	ft_fill(buff, s, 0, arg->fd);
	if ((arg->flg & M_MINUS) == M_MINUS && arg->wth > 0)
		ft_fill(buff, " ", arg->wth, arg->fd);
	ft_fill(buff, NULL, 0, arg->fd);
	return (len);
}

int			ft_letter_pars(char *s, t_arg *arg)
{
	int		cnt;

	if (arg->spe == 'c' || arg->acc < 0)
		cnt = ft_strlen(s);
	else
	{
		cnt = ft_strnlen(s, arg->acc);
		s[cnt] = 0;
	}
	arg->wth = arg->wth - cnt;
	arg->wth = arg->wth < 0 ? 0 : arg->wth;
	return (ft_letter_buff(s, arg, (cnt + arg->wth)));
}