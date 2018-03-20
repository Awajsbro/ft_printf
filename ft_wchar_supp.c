/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_supp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 14:08:53 by awajsbro          #+#    #+#             */
/*   Updated: 2018/03/20 15:40:57 by awajsbro         ###   ########.fr       */
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

char	*ft_cut_char(wint_t c, char *s)
{
	s[1] = 0;
	if (c < PF_1BYT_MAX)
		s[0] = c;
	else if (c < PF_2BYT_MAX)
	{
		s[2] = 0;
		s[1] = (PF_WEAK_BYT | (PF_6FIRST & c));
		s[0] = (PF_MSB_2BYT | (c >> 6));
	}
	else if (c < PF_3BYT_MAX)
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
	return (s);
}

size_t	ft_wcharlen(wchar_t ws)
{
	if (ws < PF_1BYT_MAX)
		return (1);
	else if (ws < PF_2BYT_MAX)
		return (2);
	else if (ws < PF_3BYT_MAX)
		return (3);
	else
		return (4);
}

size_t	ft_wstrbytlen(wchar_t *ws)
{
	int		bytlen;

	if (ws == NULL)
		return (0);
	bytlen = 0;
	while (*ws)
	{
		bytlen = bytlen + ft_wcharlen(*ws);
		ws++;
	}
	return (bytlen);
}
