/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbouillo <pbouillo@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:59:07 by pbouillo          #+#    #+#             */
/*   Updated: 2022/06/07 18:01:36 by pbouillo         ###   ########.fr       */
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

int	ft_putuint_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
	{
		len += ft_putuint_len(n / 10);
		len += ft_putuint_len(n % 10);
	}
	else
		len += ft_putchar_len(n + '0');
	return (len);
}
