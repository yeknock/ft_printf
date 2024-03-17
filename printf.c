#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

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


int	printf_format(char c, va_list ap_)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += putchar(va_arg(ap_, int));
	else if (c == 's')
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
	int count = ft_printf("Hello %s %c %s \n", "String", 'x', "isdvn");
	int d = printf("%d\n", count);
	printf("%d", d);

	return (0);
}