#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>	

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

int	ft_puthexa(unsigned int nb, char *base)
{
	int	len;

	len = 0;
	if (nb > 15)
		len += ft_puthexa(nb / 16, base);
	len += ft_putchar_len(base[nb % 16]);
	return (len);
}

int	ft_arg_handl(va_list ap, const char *s, int i)
{
	int	len;

	len = 0;
	if (s[i] == 's')
		len += ft_putstr_len(va_arg(ap, char *));
	if (s[i] == 'd' || s[i] == 'i')
		len += ft_putnbr_len(va_arg(ap, int));
	if (s[i] == 'x')
		len += ft_puthexa(va_arg(ap, int), "0123456789abcdef");
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
		if (format[i] == '%')
		{
			len += ft_arg_handl(ap, format, i + 1);
			i++;
			i++;
			continue ;
		}
		else
			len += ft_putchar_len(format[i]);
		if (format == NULL)
		{
			va_end(ap);
			len += write(1, "(null)", 6);
		}
		i++;
	}
	va_end(ap);
	return (len);
}

int	main (void)
{
	ft_printf("the %d n is %i\n", 12345, 53253);
	ft_printf("12392163982389137273289137281319wewewwwweweweweweweweweweweweweewfwefewfewfwefewfewfewf;>>>^#@&#()@#*@)$3728193\n");
	ft_printf("test %s\n", "test string");
	ft_printf("%x\n", 42);
	return (0);
}