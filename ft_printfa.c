#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

int	ft_putchar_len(char c)
{
	int	len;

	len = 0;
	len += write(1, &c, 1);
	return (len);
}

int	ft_putstr_len(char *s)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (s == NULL)
		return (len += write(1, "(null)", 6));
	while (s[i])
	{
		len += ft_putchar_len(s[i]);
		i++;
	}
	return (len);
}

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

int	ft_put_uint(unsigned int n)
{
	int	len;

	len = 0;
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

int	ft_puthexa(unsigned int nb, char *base)
{
	int	len;

	len = 0;
	if (nb > 15)
		len += ft_puthexa(nb / 16, base);
	len += ft_putchar_len(base[nb % 16]);
	return (len);
}

int	ft_puthexa_up(unsigned int nb, char *base)
{
	int	len;

	len = 0;
	if (nb > 15)
		len += ft_puthexa_up(nb / 16, base);
	len += ft_putchar_len(base[nb % 16]);
	return (len);
}

int	ft_arg_handl(va_list ap, const char *s, int i)
{
	int	len;

	len = 0;
	if (s[i] == 'c')
		len += ft_putchar_len(va_arg(ap, int));
	if (s[i] == 's')
		len += ft_putstr_len(va_arg(ap, char *));
	if (s[i] == 'd' || s[i] == 'i')
		len += ft_putnbr_len(va_arg(ap, int));
	if (s[i] == 'u')
		len += ft_put_uint(va_arg(ap, unsigned int));
	if (s[i] == 'x')
		len += ft_puthexa(va_arg(ap, unsigned int), "0123456789abcdef");
	if (s[i] == 'X')
		len += ft_puthexa_up(va_arg(ap, unsigned int), "0123456789ABCDEF");
	if (s[i] == 'p')
	{
		// len += ft_putstr_len("0x");
		len += ft_puthexa(va_arg(ap, unsigned long), "0123456789abcdef");
	}
	if (s[i] == '%')
		len += ft_putchar_len('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	ap;

	i = 0;
	len = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format == NULL)
		{
			va_end(ap);
			return (len);
		}
		if (format[i] == '%')
		{
			len += ft_arg_handl(ap, format, i + 1);
			i++;
			i++;
			continue ;
		}
		else
			len += ft_putchar_len(format[i]);
		i++;
	}
	va_end(ap);
	return (len);
}

int	main (void)
{
	void	*p = "reire";
	ft_printf("%p",p);
	ft_printf("\n");
	printf("%p", p);
	return (0);
}