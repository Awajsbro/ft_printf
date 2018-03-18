/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_charcode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 14:08:53 by awajsbro          #+#    #+#             */
/*   Updated: 2018/03/18 17:16:36 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define PF_6FIRST 0x3f
#define PF_WEAK_BYT 0x80
#define PF_MSB_2BYT 0xc0
#define PF_MSB_3BYT 0xe0
#define PF_MSB_4BYT 0xf0
#define PF_1BYT_MAX 0x80
#define PF_2BYT_MAX 0x800
#define PF_3BYT_MAX 0x10000

static int	ft_cut_char(wint_t c, char *s, t_arg *arg)
{
	if (c >= PF_1BYT_MAX && c < PF_2BYT_MAX)
	{
		s[2] = 0;
		s[1] = (PF_WEAK_BYT | (PF_6FIRST & c));
		s[0] = (PF_MSB_2BYT | (c >> 6));
	}
	else if (c >= PF_2BYT_MAX && c < PF_3BYT_MAX)
	{
		s[3] = 0;
		s[2] = (PF_WEAK_BYT | (PF_6FIRST & c));
		s[1] = (PF_WEAK_BYT | (PF_6FIRST & (c >> 6)));
		s[0] = (PF_MSB_3BYT | (PF_6FIRST & (c >> 12)));
	}
	else
	{
		s[4] = 0;
		s[3] = (PF_WEAK_BYT | (PF_6FIRST & c));
		s[2] = (PF_WEAK_BYT | (PF_6FIRST & (c >> 6)));
		s[1] = (PF_WEAK_BYT | (PF_6FIRST & (c >> 12)));
		s[0] = (PF_MSB_4BYT | (PF_6FIRST & (c >> 18)));
	}
	return (ft_str_pars(s, arg));
}

int			ft_charcode(wint_t c, t_arg *arg)
{
	char	s[5];

	if (c < 0)
		return (0);
	if (c < PF_1BYT_MAX)
	{
		s[0] = c;
		return (ft_letter_pars(s[0], arg));
	}
	return (ft_cut_char(c, s, arg));
}
