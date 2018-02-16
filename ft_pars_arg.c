/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 18:23:24 by awajsbro          #+#    #+#             */
/*   Updated: 2018/02/16 20:15:40 by awajsbro         ###   ########.fr       */
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

static int	ft_fill(char *s, int len, char c, char *s2)
{
	static int	i = 0;

	len = len + i;
	if (c != 0)
	{
		while (i <  len)
		{
			s[i] = c;
			i++;
		}
	}
	else if (s2 != NULL)
	{
		ft_strcpy(s2, s);
		i = i + ft_strlen(s2);
	}
	else
	{
		i = 0;
		if (len == 0)
			return (ft_putstr(s));
		if (len == 1)
			return (ft_putstr(ft_strupper(s)));
	}
	return (0);
}

static int ft_buff_exa(long long n, t_arg *arg, char cnt, int len)
{
	char	s[len];
	char	out[cnt];
	int		i;

	s[len] = 0;
	if ((arg->flg & M_MINUS) != M_MINUS && arg->wth > 0)
		ft_fill(s, arg->wth, ' ', "");
	if (arg->spe == 'p' || arg->spe == 'x')
		ft_fill(s, 2, 0, "0x");
	if (arg->acc > 0)
		ft_fill(s, arg->acc, '0', "");
	else if ((arg->flg & M_ZERO) == M_ZERO && arg->wth > 0)
		ft_fill(s, arg->wth, '0', "");
	ft_fill(s, cnt, 0, ft_itoab(n, 16, out));
	if ((arg->wth > 0 && (arg->flg & M_MINUS) != M_MINUS)
		&& ((arg->flg & M_ZERO) != M_ZERO || arg->acc > 0))
		ft_fill(s, arg->wth, ' ', "");
	if (arg->spe != 'X')
		ft_fill(s, 0, 0, "");
	else
		ft_fill(s, 1, 0, "");
	return (len);
}

static int ft_exa_print(long long n, t_arg *arg)
{
	char cnt;

	cnt = ft_cntb(n, 16);
	cnt = (arg->flg & M_DIEZE) == M_DIEZE ? cnt + 2 : cnt;
	arg->wth = arg->cnt - cnt - arg->acc;
	arg->wth = arg->wth > 0 ? arg->flg : 0;
	return (ft_buff_exa(n, arg, cnt, (cnt + arg->acc + arg->wth)));
}

static int	ft_exapars(char const *s, int i, va_list va, t_arg *arg)
{
	if (s[i - 1] == 'p')
	{
		arg->flg = (arg->flg | M_DIEZE);
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

int		ft_pars_arg(char const *s, int i, va_list va, t_arg *arg)
{
	if (arg->spe == 'x' || arg->spe == 'X' || arg->spe == 'p')
		return (ft_exapars(s, i, va, arg));
	return (0);
}
