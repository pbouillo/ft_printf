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

int	ft_putp(void *p, char *base)
{
	int					len;
	unsigned long long	ptr;

	ptr = (unsigned long long)p;
	len = 0;
	if (ptr > 15)
		len += ft_putp(ptr / 16, base);
	len += ft_putchar_len(base[ptr % 16]);
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
		len += ft_putp(va_arg(ap, void *), "0123456789abcdef");
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

int	main(void)
{
	char *testpointer = NULL;
	char *emptystring = "";
	int int1 = 0;
	int int2 = 0;
	int int3 = -0;
	int int4 = 0;
	int ml = ft_printf("Testtesttes! %%%%%%%%%%%%%%%% %% %d %d %s %%%%%%%% Das ist ziemlich cool! %% %% %% test mich %u %i %p %x %s %d %p %p \n", int1, int2, "TEST ME", int3, int4, testpointer, int4, NULL, 4, NULL, NULL);
	int pl = printf("Testtesttes! %%%%%%%%%%%%%%%% %% %d %d %s %%%%%%%% Das ist ziemlich cool! %% %% %% test mich %u %i %p %x %s %d %p %p \n", int1, int2, "TEST ME", int3, int4, testpointer, int4, NULL, 4, NULL, NULL);
	int ml2 = ft_printf("A %% AAA %d\n", 0);
	int pl2 = printf("A %% AAA %d\n", 0);
	int ml3 = ft_printf("");
	int pl3 = printf("");
	int ml4 = ft_printf("aa\n");
	int pl4 = printf("aa\n");
	int ml5 = ft_printf("%%\n");
	int pl5 = printf("%%\n");
	int ml6 = ft_printf("%% A %% A %% \n");
	int pl6 = printf("%% A %% A %% \n");
	int ml7 = ft_printf("!!%d %%\n", -2147483647);
	int pl7 = printf("!!%d %%\n", -2147483647);
	int ml8 = ft_printf("!!%d %% %s \n", -123123, emptystring);
	int pl8 = printf("!!%d %% %s \n", -123123, emptystring);
	int ml9 = ft_printf("!!%d %% %s %u %p \n", -123123, emptystring, (unsigned int) 4294967295, emptystring);
	int pl9 = printf("!!%d %% %s %u %p \n", -123123, emptystring, (unsigned int) 4294967295, emptystring);
	printf("================\n");
	printf("my__PRINTFLENGTH: %d\n", ml);
	printf("____PRINTFLENGTH: %d\n", pl);
	printf("================\n");
	printf("my__PRINTFLENGTH: %d\n", ml2);
	printf("____PRINTFLENGTH: %d\n", pl2);
	printf("================\n");
	printf("my__PRINTFLENGTH: %d\n", ml3);
	printf("____PRINTFLENGTH: %d\n", pl3);
	printf("================\n");
	printf("my__PRINTFLENGTH: %d\n", ml4);
	printf("____PRINTFLENGTH: %d\n", pl4);
	printf("================\n");
	printf("my__PRINTFLENGTH: %d\n", ml5);
	printf("____PRINTFLENGTH: %d\n", pl5);
	printf("================\n");
	printf("my__PRINTFLENGTH: %d\n", ml6);
	printf("____PRINTFLENGTH: %d\n", pl6);
	printf("================\n");
	printf("my__PRINTFLENGTH: %d\n", ml7);
	printf("____PRINTFLENGTH: %d\n", pl7);
	printf("================\n");
	printf("my__PRINTFLENGTH: %d\n", ml8);
	printf("____PRINTFLENGTH: %d\n", pl8);
	printf("================\n");
	printf("my__PRINTFLENGTH: %d\n", ml9);
	printf("____PRINTFLENGTH: %d\n", pl9);
	system("leaks a.out");
	return 0;
}