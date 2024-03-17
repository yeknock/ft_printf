#include <stdio.h>
#include "ft_printf.h"


static	int	printf_format(char c, va_list ap_)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(ap_, int));
	else if (c == 's')
		count += ft_putstr(va_arg(ap_, char *));
	else if (c == 'd')
		count += print_digit(va_arg(ap_, int));
	else if (c == 'i')
		count += print_digit(va_arg(ap_, int));
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






// int main()
// {
// 	ft_printf(" %c %c %c", 'c', 'v', 'b');

// 	return (0);
// }