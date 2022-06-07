/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbouillo <pbouillo@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:02:44 by pbouillo          #+#    #+#             */
/*   Updated: 2022/06/07 12:58:25 by pbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
		len += ft_put_uint_len(va_arg(ap, unsigned int));
	if (s[i] == 'x')
		len += ft_puthexa(va_arg(ap, unsigned int), "0123456789abcdef");
	if (s[i] == 'X')
		len += ft_puthexa(va_arg(ap, unsigned int), "0123456789ABCDEF");
	if (s[i] == 'p')
		len += ft_putp(va_arg(ap, unsigned long long));
	if (s[i] == '%')
		len += ft_putchar_len('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	ap;

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
