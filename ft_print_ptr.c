/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbouillo <pbouillo@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:00:49 by pbouillo          #+#    #+#             */
/*   Updated: 2022/06/11 10:32:22 by pbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	conv_ptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr >= 16)
	{
		len += conv_ptr(ptr / 16);
		len += conv_ptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			len += ft_putchar_len(ptr + '0');
		else
			len += ft_putchar_len(ptr - 10 + 'a');
	}
	return (len);
}

int	ft_putptr(long ptr)
{
	int	len;

	len = 0;
	len += write(1, "0x", 2);
	if (ptr == 0)
		len += write(1, "0", 1);
	else
		len += conv_ptr(ptr);
	return (len);
}
