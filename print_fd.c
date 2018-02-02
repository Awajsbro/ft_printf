/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:23:07 by awajsbro          #+#    #+#             */
/*   Updated: 2018/02/02 18:40:37 by awajsbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_fd(char const s, int *i, va_list va)
{
	char	*line;
	size_t	len;
	int		nb;
	int		fd;

	len = 0;
	nb = s[*i + 5] == '*' ? va_arg(va, int) : 0;
	*i = s[*i + 5] == '*' ? (*i + 5) : (*i + 4);
	fd = va_arg(va, int);
	while (get_next_line(fd, &line) == 1 && --nb != 0)
	{
		len = ft_strlen(line) + len;
		ft_strclr(line);
		ft_strdel(&line);
	}
	return (len);
}
