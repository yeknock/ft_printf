#include <stdio.h>
#include "ft_printf.h"

int	putchar(int c)
{
	write(1, &c, 1);
	return (1);
}


int	putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		putchar(str[i]);
		i++;
	}
	return (i);
}



int	print_digit(int a)
{
	char	*s;
	int		count;

	count = 0;
	s = ft_itoa(a);
	count = putstr(s);
	return (count);
}



static	int	printf_format(char c, va_list ap_)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += putchar(va_arg(ap_, int));
	else if (c == 's')
		count += putstr(va_arg(ap_, char *));
	else if (c == 'd')
		count += print_digit(va_arg(ap_, int));
	else if (c == 'i')
		count += putstr(va_arg(ap_, char *));
	else if (c == 'u')
		count += putstr(va_arg(ap_, char *));
	else if (c == 'x')
		count += putstr(va_arg(ap_, char *));
	else if (c == 'X')
		count += putstr(va_arg(ap_, char *));
	else if (c == '%')
		count += putstr(va_arg(ap_, char *));
	else
		count += write(1, &c, 1);
	return (count);
}


int	ft_printf(const char *p, ...)
{
	int	i;
	int	count;
	va_list	ap;

	i = 0;
	count = 0;
	va_start(ap, p);
	while (p[i] != '\0')
	{
		if (p[i] == '%')
			count += printf_format(p[++i], ap);
		else
			count += write(1, &p[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}






int main()
{
	ft_printf("Hello I'm %d", 13);

	return (0);
}