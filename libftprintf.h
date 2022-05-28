/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbouillo <pbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 13:32:22 by pbouillo          #+#    #+#             */
/*   Updated: 2022/05/28 16:14:28 by pbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int			ft_printf(const char *format, ...);
int			ft_putchar_len(char c);
int			ft_putstr_len(char *s);
int			ft_puthexa(unsigned int nb, char *base);
int			ft_putnbr_len(int n);
int			ft_put_uint(unsigned int n);
int			conv_ptr(unsigned long long ptr);
int			ft_putp(unsigned long long ptr);
int			ft_arg_handl(va_list ap, const char *s, int i);

#endif