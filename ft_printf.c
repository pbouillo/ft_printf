/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbouillo <pbouillo@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 13:31:06 by pbouillo          #+#    #+#             */
/*   Updated: 2022/05/24 17:16:34 by pbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// int	ft_printf(const char *format, ...)
// {
// 	va_list	ap;
// 	t_print	print;

// 	va_start(ap, format);
// 	print.len = 0;
// 	print.width = 0;
// 	while (*format)
// 	{
// 		if (*format == '%')
// 			format = search_arg(ap, format + 1, &print);
// 		else
// 			format = read_text(&print, format);
// 		if (format == NULL)
// 		{
// 			ft_putstr("(null)");
// 			va_end(ap);
// 			return (print.len);
// 		}
// 	}
// 	va_end(ap);
// 	return (print.len);
// }
