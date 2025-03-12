CC = cc
# CFLAGS = -Wall -Werror -Wextra
CFLAGS = -Wall

# SRC = a.c r.c
SRC = ./Mandatory/src/main.c ./Mandatory/src/initialize.c ./Mandatory/src/arguments.c ./Mandatory/src/mandelbrot.c ./Mandatory/src/julia.c ./Mandatory/src/events.c ./Mandatory/src/utils.c

OBJ = $(SRC:.c=.o)

# includs = main.h
includs = /Mandatory/main.h


libft_DIR = ./42_Libft
libft = $(libft_DIR)/libft.a

NAME = fractol

all: $(NAME) clean

#-----------------------------------------------------------------------------------------

#											On Mac :

# $(NAME): $(OBJ)
# #	make -C $(libft_DIR)
# 	$(CC) $(CFLAGS) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(libft)

# %.o: %.c $(includs) $(libft_DIR)/libft.h
# 	$(CC) $(CFLAGS) -Imlx -c $< -o $@

# clean: 
# #	make -C $(libft_DIR) clean
# 	rm -rf $(OBJ)

#-----------------------------------------------------------------------------------------

#											On Linux :

$(NAME): $(OBJ)
#	make -C $(libft_DIR)
	make -C mlx_Linux
	$(CC) $(CFLAGS) $(OBJ) -Lmlx_Linux -l:libmlx_Linux.a -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) $(libft)

%.o: %.c $(includs) $(libft_DIR)/libft.h
	$(CC) $(CFLAGS)  -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean: 
#	make -C $(libft_DIR) clean
#	make -C mlx_Linux  clean
	rm -rf $(OBJ)

#-----------------------------------------------------------------------------------------

fclean: clean
#	make -C $(libft_DIR) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re