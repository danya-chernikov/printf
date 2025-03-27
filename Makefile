CC=cc
NAME=libftprintf.a
CFLAGS=-Wall -Werror -Wextra -g3 -O0

SRCS=ft_printf.c numeric.c non_numeric.c utils.c

OBJS=ft_printf.o numeric.o non_numeric.o utils.o

$(NAME) : $(OBJS)
	cd libft/ && $(MAKE) all && $(MAKE) bonus # First let's bulid the Libft
	ar rcs $(NAME) $(OBJS) # Building ft_printf library

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

%.o : %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re
