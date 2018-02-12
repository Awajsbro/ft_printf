/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 18:23:24 by awajsbro          #+#    #+#             */
/*   Updated: 2018/02/12 19:16:04 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define M_DIEZE	0x01
#define M_MINUS	0x02
#define M_MORE	0x04
#define M_SPACE	0x08
#define M_ZERO	0x10

// static int ft_minnb(t_arg *arg, long long n)
// {
// 	int cnt;

// 	if (arg->spe == 'u' || arg->spe == 'd' ||arg->spe == 'i')
// 		cnt = arg->flg ft_cntb(n, 10);
// 	else if (arg->spe == 'p' || arg->spe == 'x')
// 		cnt = arg->flg == '#' ? ft_cntb(n, 16) + 2 : ft_cntb(n, 16);
// 	else
// 		cnt = arg->flg == '#' ? ft_cntb(n, 8) + 2 : ft_cntb(n, 8);

// }

// static int ft_majnb(t_arg arg, long long n)

// static int ft_science(t_arg arg, long long n)

// static int ft_str()

static int ft_format_nb(long long n, t_arg *arg)
{

}

int		ft_pars_arg(char *s, int *i, va_list va, t_arg *arg)
{
	if (arg->spe == 'p' )
		return(ft_format_nb(arg, (long long)va_arg(va, void*)));
	if (arg->spe == 'x')
}
