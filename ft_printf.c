/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:55:44 by awajsbro          #+#    #+#             */
/*   Updated: 2018/03/03 16:58:13 by awajsbro         ###   ########.fr       */
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

static char	ft_flag(char const *s, int *i, t_arg *arg)
{
	arg->flg = 0;
	while (s[*i] == ' ' || s[*i] == '+' || s[*i] == '-'
		|| s[*i] == '#' || s[*i] == '0')
	{
		if (s[*i] == ' ')
			arg->flg = (arg->flg | M_SPACE);
		else if (s[*i] == '+')
			arg->flg = (arg->flg | M_MORE);
		else if (s[*i] == '-')
			arg->flg = (arg->flg | M_MINUS);
		else if (s[*i] == '0')
			arg->flg = (arg->flg | M_ZERO);
		else
			arg->flg = (arg->flg | M_DIEZE);
		(*i)++;
	}
	arg->flg = (arg->flg & M_MORE) == M_MORE ? (arg->flg & M_NSPACE) : arg->flg;
	return (arg->flg);
}

static void	ft_initarg(char const *s, int *i, va_list va, t_arg *arg)
{
	arg->acc = -1;
	arg->flg = ft_flag(s, i, arg);
	arg->wth = s[*i] == '*' ? va_arg(va, int) : ft_atoi(&s[*i]);
	while (ft_isdigit(s[*i]) == 1 || s[*i] == '*')
		(*i)++;
	if (s[*i] == '.')
		arg->acc = s[++*i] == '*' ? va_arg(va, int) : ft_atoi(&s[*i]);
	while (ft_isdigit(s[*i]) == 1 || s[*i] == '*')
		(*i)++;
	while (s[*i] == 'h' || s[*i] == 'l' || s[*i] == 'j' || s[*i] == 'z'
		|| s[*i] == 't' || s[*i] == 'L')
		(*i)++;
	arg->spe = (s[(*i)++]);
	if (arg->spe == 0)
		(*i)--;
	if (arg->wth < 0)
	{
		arg->wth = -1 * (arg->wth);
		arg->flg = (arg->flg | M_MINUS);
	}
	if ((arg->flg & M_MINUS) == M_MINUS)
		arg->flg = (arg->flg & M_NZERO);
}

static int	ft_pars_type(char const *s, int *i, va_list va, t_arg *arg)
{
	(*i)++;
	if (s[*i] == '{')
		return (ft_pars_color(s, i, arg->fd));
	else if (s[*i] == '[')
		return (ft_define_fd(s, i, va, arg));
	ft_initarg(s, i, va, arg);
	if (arg->spe == '%')
		return (ft_letter_pars('%', arg));
	else if (arg->spe == 'x' || arg->spe == 'X' || arg->spe == 'p'
		|| arg->spe == 'U' || arg->spe == 'u' || arg->spe == 'o'
			|| arg->spe == 'O' || arg->spe == 'b' || arg->spe == 'B')
		return (ft_unsigned_pars(s, *i, va, arg));
	else if (arg->spe == 'd' || arg->spe == 'D' || arg->spe == 'i')
		return (ft_signed_pars(s, *i, va, arg));
	else if ((arg->spe == 'c' || arg->spe == 's') && (s[*i - 2] != 'l'))
		return (arg->spe != 'c' ? ft_str_pars(va_arg(va, char*), arg)
			: ft_letter_pars(va_arg(va, int), arg));
	// else if (arg->spe == 'C' || arg->spe == 'c')
	// 	return (0);
	// else if (arg->spe == 'S' || arg->spe == 's')
	// 	return (0);
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
