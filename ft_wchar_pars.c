/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_pars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 16:59:41 by awajsbro          #+#    #+#             */
/*   Updated: 2018/03/21 18:12:45 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define PF_1BYT_MAX 0x80
#define PF_2BYT_MAX 0x800
#define PF_3BYT_MAX 0x10000

static int		ft_wtos(wchar_t *ws, size_t len, t_arg *arg)
{
	char	s[len + 1];
	size_t	bytlen;

	len = 0;
	s[0] = 0;
	if (arg->spe == 'c' || arg->spe == 'C')
	{
		ft_cut_char(*ws, s);
	}
	else
	{
		while (*ws)
		{
			bytlen = ft_wcharlen(*ws);
			if ((bytlen + len) <= (size_t)arg->acc)
			{
				ft_cut_char(*ws, &s[len]);
				len = len + bytlen;
			}
			ws++;
		}
	}
	return (ft_str_pars(s, arg));
}

int				ft_wstr_pars(wchar_t *ws, t_arg *arg)
{
	size_t	len;

	if (!ws)
		return (ft_str_pars(NULL, arg));
	if ((len = ft_wstrbytlen(ws)) == 1)
		return (ft_letter_pars((char)ws[0], arg));
	return (ft_wtos(ws, len, arg));
}

int				ft_wchar_pars(wint_t wi, t_arg *arg)
{
	if (wi < 0)
		return (0);
	if (wi < PF_1BYT_MAX)
		return (ft_letter_pars((char)wi, arg));
	return (ft_wtos(&wi, ft_wcharlen(wi), arg));
}
