#include "ft_printf.h"

int	ft_putchar(char c)
{
	if (c >= 32)
		write(1, &c, 1);
	return (1);
}


int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}


int print_digit(int d)
{
	int		count;
	char	*str;

	count = 0;
	str = ft_itoa(d);
	count = ft_putstr(str);
	free(str);
	return (count);
}