/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbouillo <pbouillo@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 13:32:22 by pbouillo          #+#    #+#             */
/*   Updated: 2022/06/11 14:50:59 by pbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int					ft_printf(const char *format, ...);
int					ft_putchar_len(char c);
int					ft_putstr_len(char *s);
int					ft_puthexa(unsigned int nb, char *base);
int					ft_putnbr_len(int n);
int					ft_putunbr_len(unsigned int n);
int					ft_putptr(unsigned long ptr, char *base);
int					ft_arg_handl(va_list ap, const char *s, int i);

#endif