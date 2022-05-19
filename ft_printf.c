/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbouillo <pbouillo@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 13:31:06 by pbouillo          #+#    #+#             */
/*   Updated: 2022/05/19 17:35:24 by pbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	va_start(args, format);
	t_print	print;
	print.len = 0;
	print.width = 0;
	
	
	return (print.len);
}
