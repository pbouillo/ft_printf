/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbouillo <pbouillo@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:00:24 by pbouillo          #+#    #+#             */
/*   Updated: 2022/05/24 14:01:45 by pbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

const char	*parse_arg(va_list ap, const char *format, t_print *print)
{
	int				di;
	int				c;
	unsigned long	p;
	unsigned int	u;
	unsigned int	x;
	unsigned int	X;
	char			*s;

	if (*format == 'd' || *format == 'i')
	{
		di = va_arg(ap, int);
		ft_putnbr(di);
		print->len += ft_intlen(di);
	}
	else if (*format == 's')
	{
		s = va_arg(ap, char *);
		if (s == NULL)
		{
			write(1, "(null)", 6);
			print->len += 6;
		}
		else
		{
			ft_putstr(s);
			print->len += ft_strlen(s);
		}
	}
	else if (*format == 'x')
	{
		
	}
}
