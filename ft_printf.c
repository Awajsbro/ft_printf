/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:55:44 by awajsbro          #+#    #+#             */
/*   Updated: 2018/03/15 17:28:37 by awajsbro         ###   ########.fr       */
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

static char	ft_get_flag(char const *s, int *i, t_arg *arg)
{
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
	return (arg->flg);
}

static int ft_get_with_n_accur(char const *s, int *i, va_list va)
{
	int	ret;
// ft_putnbr(*i); ft_putendl(" --> entre get");
	ret = 0;
	while (s[(*i)] == '*' || ft_isdigit(s[*i]) == 1)
	{
// ft_putnbr(*i); ft_putendl(" --> enterer while");
		if (s[(*i)++] == '*')
			ret = va_arg(va, int);
		else
		{
			(*i)--;
// ft_putnbr(*i); ft_putendl(" --> avant atoi");
			ret = ft_atoi(&s[*i]);
			while (ft_isdigit(s[*i]) == 1)
				(*i)++;
		}
	}
	return (ret);
}

static void	ft_get_arg(char const *s, int *i, va_list va, t_arg *arg)
{
	while (s[*i] == ' ' || s[*i] == '+' || s[*i] == '-' || s[*i] == '#'
		|| s[*i] == '*' || s[*i] == '.' || s[*i] == 'h' || s[*i] == 'l'
			|| s[*i] == 'j' || s[*i] == 'z' || s[*i] == 't' || s[*i] == 'L'
				|| ft_isdigit(s[*i]) == 1)
	{
		arg->flg = ft_get_flag(s, i, arg);
// ft_putnbr(*i); ft_putendl(" --> avant if");
		if (ft_isdigit(s[(*i)]) == 1 || s[(*i)] == '*')
			arg->wth = ft_get_with_n_accur(s, i, va);
// ft_putnbr(arg->wth); ft_putendl(" --> sortie get");
		if (s[(*i)++] == '.')
			arg->acc = ft_get_with_n_accur(s, i, va);
		else
			(*i)--;
		while (s[*i] == 'h' || s[*i] == 'l' || s[*i] == 'j' || s[*i] == 'z'
			|| s[*i] == 't' || s[*i] == 'L')
			(*i)++;
	}
}

static void ft_init_arg(char const *s, int *i, va_list va, t_arg *arg)
{
	arg->flg = 0;
	arg->wth = 0;
	arg->acc = -1;
	ft_get_arg(s, i, va, arg);
	arg->spe = (s[(*i)++]);
// ft_putnbr(arg->flg); ft_putendl(" --> flag");
// ft_putnbr(arg->wth); ft_putendl(" --> with");
// ft_putnbr(arg->acc); ft_putendl(" --> acuura");
// ft_putchar(arg->spe); ft_putendl(" --> specif");
	if (arg->spe == 0)
		(*i)--;
	if (arg->wth < 0)
	{
		arg->wth = -1 * (arg->wth);
		arg->flg = (arg->flg | M_MINUS);
	}
	if ((arg->flg & M_MINUS) == M_MINUS || arg->acc > -1)
		arg->flg = (arg->flg & M_NZERO);
	if ((arg->flg & M_MORE) == M_MORE)
		arg->flg = (arg->flg & M_NSPACE);
}

static int	ft_pars_type(char const *s, int *i, va_list va, t_arg *arg)
{
	(*i)++;
	if (s[*i] == '{')
		return (ft_pars_color(s, i, arg->fd));
	else if (s[*i] == '[')
		return (ft_define_fd(s, i, va, arg));
	ft_init_arg(s, i, va, arg);
// ft_putendl("pourauoi ca marche pas");
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
	else if (arg->spe == 'C' || arg->spe == 'c')
		return (0);
	else if (arg->spe == 'S' || arg->spe == 's')
		return (0);
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
