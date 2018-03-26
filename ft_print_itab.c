/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_itab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 10:09:03 by awajsbro          #+#    #+#             */
/*   Updated: 2018/03/22 11:13:13 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_buff_tab(int *tab, int len, int cnt, t_arg *arg)
{
	char		out[cnt + 1];
	char		buff[(3 + cnt + (2 * (len - 1)))];
	int			i;

	i = -1;
	cnt = 1;
	buff[0] = '[';
	while (++i < len - 1)
	{
		ft_itoab(tab[i], 10, out);
		ft_strcpy(&buff[cnt], out);
		cnt = ft_strlen(buff) + 2;
		buff[cnt - 2] = ',';
		buff[cnt - 1] = ' ';
	}
	ft_itoab(tab[i], 10, out);
	ft_strcpy(&buff[cnt], out);
	cnt = ft_strlen(buff);
	buff[cnt] = ']';
	buff[cnt + 1] = 0;
	return (ft_putstr_fd(buff, arg->fd));
}

int			ft_print_itab(va_list va, t_arg *arg)
{
	int			cnt;
	int			len;
	int			tmp;
	int			*tab;

	len = va_arg(va, int);
	tab = va_arg(va, int*);
	if (tab == NULL || len < 1)
		return (0);
	arg->base = 10;
	cnt = 0;
	tmp = len;
	while (tmp--)
	{
		cnt = cnt + ft_cntb(tab[tmp], arg->base);
		if (tab[tmp] < 0)
			cnt++;
	}
	return (ft_buff_tab(tab, len, cnt, arg));
}
