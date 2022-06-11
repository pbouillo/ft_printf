/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbouillo <pbouillo@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:59:25 by pbouillo          #+#    #+#             */
/*   Updated: 2022/06/11 14:50:48 by pbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned int nb, char *base)
{
	int	len;

	len = 0;
	if (nb >= 16)
	{
		len += ft_puthexa(nb / 16, base);
		nb %= 16;
	}
	if (nb < 16)
	{
		len += write(1, &base[nb], 1);
	}
	return (len);
}

int	ft_putptr(unsigned long ptr, char *base)
{
	int	len;

	len = 0;
	if (ptr == 0)
		len += write(1, "0", 1);
	else
	{
		if (ptr >= 16)
		{
			len += ft_putptr(ptr / 16, base);
			ptr %= 16;
		}
		if (ptr < 16)
		{
			len += write(1, &base[ptr], 1);
		}
		return (len);
	}
	return (len);
}
