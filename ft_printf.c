/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:55:44 by awajsbro          #+#    #+#             */
/*   Updated: 2018/03/19 18:39:59 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define PF_LEN_NONE	0
#define PF_LEN_HH	1
#define PF_LEN_H	2
#define PF_LEN_Z	3
#define PF_LEN_T	4
#define PF_LEN_J	5
#define PF_LEN_L	6
#define PF_LEN_LL	7

static int	ft_pars_type(char const *s, int *i, va_list va, t_arg *arg)
{
	(*i)++;
	if (s[*i] == '{')
		return (ft_pars_color(s, i, arg->fd));
	else if (s[*i] == '[')
		return (ft_define_fd(s, i, va, arg));
	ft_init_arg(s, i, va, arg);
	if (arg->spe == '%')
		return (ft_letter_pars('%', arg));
	else if (arg->spe == 'x' || arg->spe == 'X' || arg->spe == 'p'
		|| arg->spe == 'U' || arg->spe == 'u' || arg->spe == 'o'
			|| arg->spe == 'O' || arg->spe == 'b' || arg->spe == 'B')
		return (ft_unsigned_pars(va, arg));
	else if (arg->spe == 'd' || arg->spe == 'D' || arg->spe == 'i')
		return (ft_signed_pars(va, arg));
	else if ((arg->spe == 'c' || arg->spe == 's') && arg->len != PF_LEN_L)
		return (arg->spe != 'c' ? ft_str_pars(va_arg(va, char*), arg)
			: ft_letter_pars(va_arg(va, int), arg));
	else if (arg->spe == 'C' || arg->spe == 'c')
		return (ft_wchar_pars(va_arg(va, wint_t), arg));
	else if (arg->spe == 'S' || arg->spe == 's')
		return (ft_wstr_pars(va_arg(va, wchar_t*), arg));
	else if (arg->spe == 0)
		return (0);
	return (ft_letter_pars(arg->spe, arg));
}

int			ft_printf(char const *s, ...)
{
	va_list	va;
	t_arg	arg;
	int		i;
	int		len;

	if (s == NULL)
		return (-1);
	len = 0;
	va_start(va, s);
	arg.fd = 1;
	while (s[0] != 0)
	{
		i = ft_strclen(s, '%');
		len = len + ft_putstrn_fd(s, arg.fd, i);
		if (s[i] == '%')
			len = len + ft_pars_type(s, &i, va, &arg);
		if (i == -42)
			break ;
		s = s + i;
		i = 0;
	}
	len = len < 0 ? -1 : len;
	va_end(va);
	return (i == -42 ? -1 : len);
}
