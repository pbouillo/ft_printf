/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbouillo <pbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:59:25 by pbouillo          #+#    #+#             */
/*   Updated: 2022/05/28 16:00:30 by pbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_puthexa(unsigned int nb, char *base)
{
	int	len;

	len = 0;
	if (nb > 15)
		len += ft_puthexa(nb / 16, base);
	len += ft_putchar_len(base[nb % 16]);
	return (len);
}
