FILES	= gnl/get_next_line_utils.c \
		gnl/get_next_line.c \
		get_color.c \
		map.c \
		main.c \
		parse.c

SRCS	= $(addprefix srcs/, $(FILES))

OBJS	= $(SRCS:.c=.o)

CC		= cc

CFLAGS	= -Wall -Wextra -Werror -g3

NAME	= fdf

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: re fclean clean all