/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbouillo <pbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:00:49 by pbouillo          #+#    #+#             */
/*   Updated: 2022/05/28 17:14:55 by pbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	conv_ptr(unsigned long long ptr)
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

int	ft_putp(unsigned long long ptr)
{
	int	len;

	len = 0;
	len += write(1, &"0x", 2);
	if (ptr == 0)
		len += write(1, "0", 1);
	else
		len += conv_ptr(ptr);
	return (len);
}
