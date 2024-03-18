#include "ft_printf.h"

static	int	int_len(unsigned int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static	char	*fill_str(char *str, unsigned int n)
{
	int	i;

	i = int_len(n);
	str[i] = '\0';
	while (i > 0 && n)
	{
		str[i - 1] = (n % 10) + 48;
		n = n / 10;
		i--;
	}
	return (str);
}

char	*ft_unsigned_itoa(unsigned int n)
{
	char	*str;
	int		i;

	i = int_len(n);
	if (n == 0)
		return (ft_strdup("0"));
	str = (char *)malloc(i + 1);
	if (!str)
		return (0);
	fill_str(str, n);
	return (str);
}
