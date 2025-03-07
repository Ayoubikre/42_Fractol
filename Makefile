CC = cc
# CFLAGS = -Wall -Werror -Wextra
CFLAGS = -Wall

SRC = a.c
OBJ = $(SRC:.c=.o)

NAME = fractol

all: $(NAME)

$(NAME): $(OBJ)
	make -C mlx_Linux 
	$(CC) $(CFLAGS) $(OBJ) -Lmlx_Linux -l:libmlx_Linux.a -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c main.h
	$(CC) $(CFLAGS)  -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean: 
	make -C mlx_Linux  clean
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re