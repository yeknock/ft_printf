#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>


int	    ft_printf(const char *p, ...);
int 	ft_putchar(char c);
int 	ft_putstr(char *str);
int     print_digit(int d);
char	*ft_itoa(int n);
char	*ft_strdup(const char *str);
size_t	ft_strlen(const char *str);


#endif