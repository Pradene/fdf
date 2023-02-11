FILES	= gnl/get_next_line_utils.c \
		gnl/get_next_line.c \
		get_color.c \
		key.c \
		map.c \
		main.c \
		parse.c \
		pixel_put.c \
		window.c

SRCS	= $(addprefix srcs/, $(FILES))

OBJS	= $(SRCS:.c=.o)

CC		= cc

CFLAGS	= -Wall -Wextra -Werror -g3

NAME	= fdf

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: re fclean clean all