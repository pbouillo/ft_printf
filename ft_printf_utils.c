/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbouillo <pbouillo@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 11:46:43 by pbouillo          #+#    #+#             */
/*   Updated: 2022/12/22 11:49:57 by pbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_len(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		len += write(1, "-2147483648", 11);
		return (len);
	}
	if (n < 0)
	{
		n *= -1;
		len += ft_putchar_len('-');
	}
	if (n >= 10)
	{
		len += ft_putnbr_len(n / 10);
		len += ft_putnbr_len(n % 10);
	}
	else
		len += ft_putchar_len(n + '0');
	return (len);
}

int	ft_putunbr_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
	{
		len += ft_putunbr_len(n / 10);
		len += ft_putunbr_len(n % 10);
	}
	else
		len += ft_putchar_len(n + '0');
	return (len);
}

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
