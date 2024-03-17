CC = cc
FLAGS = -Wall -Wextra -Werror
SOURCE = ft_printf.c ft_printf_utils.c ft_strdup.c ft_itoa.c ft_strlen.c
OBJECTS = $(SOURCE:.c=.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:  all clean fclean re $(NAME)