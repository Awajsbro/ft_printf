/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 14:21:48 by awajsbro          #+#    #+#             */
/*   Updated: 2018/03/20 17:10:15 by awajsbro         ###   ########.fr       */
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
#define PF_LEN_NONE	0
#define PF_LEN_HH	1
#define PF_LEN_H	2
#define PF_LEN_Z	3
#define PF_LEN_T	4
#define PF_LEN_J	5
#define PF_LEN_L	6
#define PF_LEN_LL	7

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

static int	ft_get_with_n_accur(char const *s, int *i, va_list va)
{
	int	ret;

	ret = 0;
	while (s[(*i)] == '*' || ft_isdigit(s[*i]) == 1)
	{
		if (s[(*i)++] == '*')
			ret = va_arg(va, int);
		else
		{
			(*i)--;
			ret = ft_atoi(&s[*i]);
			while (ft_isdigit(s[*i]) == 1)
				(*i)++;
		}
	}
	return (ret);
}

static void	ft_get_length(char const *s, int *i, t_arg *arg)
{
	while (s[*i] == 'h' || s[*i] == 'l' || s[*i] == 'j' || s[*i] == 'z'
		|| s[*i] == 't' || s[*i] == 'L')
	{
		(*i)++;
		if ((s[(*i) - 1] == 'l' && s[(*i)] == 'l') || s[(*i) - 1] == 'L')
			arg->len = PF_LEN_LL;
		else if (s[(*i) - 1] == 'l')
			arg->len = arg->len < PF_LEN_L ? PF_LEN_L : arg->len;
		else if (s[(*i) - 1] == 'j')
			arg->len = arg->len < PF_LEN_J ? PF_LEN_J : arg->len;
		else if (s[(*i) - 1] == 't')
			arg->len = arg->len < PF_LEN_T ? PF_LEN_T : arg->len;
		else if (s[(*i) - 1] == 'z')
			arg->len = arg->len < PF_LEN_Z ? PF_LEN_Z : arg->len;
		else if (s[(*i) - 1] == 'h' && s[*i] != 'h')
			arg->len = arg->len < PF_LEN_H ? PF_LEN_H : arg->len;
		else if (s[(*i) - 1] == 'h')
			arg->len = arg->len < PF_LEN_HH ? PF_LEN_HH : arg->len;
		if (s[*i] == 'h' || s[*i] == 'l')
			(*i)++;
	}
}

static void	ft_get_arg(char const *s, int *i, va_list va, t_arg *arg)
{
	while (s[*i] == ' ' || s[*i] == '+' || s[*i] == '-' || s[*i] == '#'
		|| s[*i] == '*' || s[*i] == '.' || s[*i] == 'h' || s[*i] == 'l'
			|| s[*i] == 'j' || s[*i] == 'z' || s[*i] == 't' || s[*i] == 'L'
				|| ft_isdigit(s[*i]) == 1)
	{
		arg->flg = ft_get_flag(s, i, arg);
		if (ft_isdigit(s[(*i)]) == 1 || s[(*i)] == '*')
			arg->wth = ft_get_with_n_accur(s, i, va);
		if (s[(*i)++] == '.')
			arg->acc = ft_get_with_n_accur(s, i, va);
		else
			(*i)--;
		ft_get_length(s, i, arg);
	}
}

void		ft_init_arg(char const *s, int *i, va_list va, t_arg *arg)
{
	arg->flg = 0;
	arg->wth = 0;
	arg->acc = -1;
	arg->len = PF_LEN_NONE;
	ft_get_arg(s, i, va, arg);
	arg->spe = (s[(*i)++]);
	if (arg->spe == 0)
		(*i)--;
	if (arg->wth < 0)
	{
		arg->wth = -1 * (arg->wth);
		arg->flg = (arg->flg | M_MINUS);
	}
	if ((arg->flg & M_MORE) == M_MORE)
		arg->flg = (arg->flg & M_NSPACE);
}
