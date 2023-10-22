NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

FILES =	ft_printf.c \
		check_flags.c \
		get_precison.c \
		helper01.c helper02.c helper03.c helper04.c
OBJS = $(SRCS:.c=.o)

SRCS = $(addprefix src/, $(FILES))

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

bonus:
	make all

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re