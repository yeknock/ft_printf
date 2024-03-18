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
		n = n / 16;
	}
	return (i);
}

static	char	letters_check(int remainder)
{
	if (remainder == 10)
		return ('A');
	else if (remainder == 11)
		return ('B');
	else if (remainder == 12)
		return ('C');
	else if (remainder == 13)
		return ('D');
	else if (remainder == 14)
		return ('E');
	return ('F');
}

static	char	*string_reverse(char *str)
{
	unsigned	int	i;
	unsigned	int	j;

	i = 0;
	if (str)
	{
		j = ft_strlen(str) - 1;
		char	*rev_str = (char *)malloc((sizeof(char) * ft_strlen(str)) + 1);
		if (!rev_str)
			return (0);
		while (str[i] != '\0')
		{
			rev_str[i] = str[j];
			i++;
			j--;
		}
		rev_str[i] = '\0';
		free(str);
		return (rev_str);
	}
	return (0);
}

static  char	*hex_upper(unsigned int n)
{
	char	*str;
	int		rem;
	unsigned	int	i;

	rem = 0;
	i = 0;
	str = (char *)malloc((sizeof(char) * int_len(n)) + 1);
	if (!str)
		return (0);
	while (n)
	{
		rem = n % 16;
		if (rem <= 9)
			str[i] = rem + 48;
		else
			str[i] = letters_check(rem);
		n = n / 16;
		i++;
	}
	return (string_reverse(str));
}

int	put_hex_upper(unsigned int num)
{
	unsigned	int	i;
	char	*str;
	char	c;

	i = 0;
	if (num == 0)
	{
		c = '0';
		return (write(1, &c, 1));
	}
	str = hex_upper(num);
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	free(str);
	return (i);
}
