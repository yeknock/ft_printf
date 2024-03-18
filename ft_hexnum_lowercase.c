#include "ft_printf.h"

static	int	int_len(int n)
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
		return ('a');
	else if (remainder == 11)
		return ('b');
	else if (remainder == 12)
		return ('c');
	else if (remainder == 13)
		return ('d');
	else if (remainder == 14)
		return ('e');
	return ('f');
}

char *hex_lower(int n)
{
	char *str;
	int rem;
	int i;

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
	str[i] = '\0';
	return (str);
}