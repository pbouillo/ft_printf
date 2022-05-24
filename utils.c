/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbouillo <pbouillo@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:22:32 by pbouillo          #+#    #+#             */
/*   Updated: 2022/05/24 13:58:50 by pbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/* */

const char	*read_text(t_print *print, const char *format)
{
	char	*next;

	next = strchr_perc(format);
	if (next)
		print->width = next - format;
	else
		print->width = ft_strlen(format);
	write(1, format, print->width);
	print->len = print->width;
	while (*format && *format != '%')
		++format;
	return (format);
}

char	*strchr_perc(const char *s)
{
	while (*s)
	{
		if (*s == '%')
			return ((char *)s);
		s++;
	}
	if (*s == '\0')
		return ((char *)s);
	return (NULL);
}
