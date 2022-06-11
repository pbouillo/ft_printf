/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbouillo <pbouillo@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:02:44 by pbouillo          #+#    #+#             */
/*   Updated: 2022/06/11 14:51:55 by pbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_arg_handl(va_list ap, const char *s, int i)
{
	int	len;

	len = 0;
	if (s[i] == 'c')
		len += ft_putchar_len(va_arg(ap, int));
	if (s[i] == 's')
		len += ft_putstr_len(va_arg(ap, char *));
	if (s[i] == 'd' || s[i] == 'i')
		len += ft_putnbr_len(va_arg(ap, int));
	if (s[i] == 'u')
		len += ft_putunbr_len(va_arg(ap, unsigned int));
	if (s[i] == 'x')
		len += ft_puthexa(va_arg(ap, int), "0123456789abcdef");
	if (s[i] == 'X')
		len += ft_puthexa(va_arg(ap, int), "0123456789ABCDEF");
	if (s[i] == 'p')
	{
		len += write(1, "0x", 2);
		len += ft_putptr((unsigned long) va_arg(ap, void *),
				"0123456789abcdef");
	}
	if (s[i] == '%')
		len += ft_putchar_len('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	ap;

	if (format == 0)
		return (0);
	i = 0;
	len = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_arg_handl(ap, format, i + 1);
			i++;
			i++;
			continue ;
		}
		else
			len += ft_putchar_len(format[i]);
		i++;
	}
	va_end(ap);
	return (len);
}
