CC = cc
# CFLAGS = -Wall -Werror -Wextra
CFLAGS = -Wall

SRC = a.c
OBJ = $(SRC:.c=.o)

libft_DIR = ./42_Libft
libft = $(libft_DIR)/libft.a

NAME = fractol

all: $(NAME)

#-----------------------------------------------------------------------------------------

#											On Mac :

$(NAME): $(OBJ)
#	make -c $(libft_DIR)
	$(CC) $(CFLAGS) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(libft)

%.o: %.c main.h $(libft_DIR)/libft.h
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean: 
#	make -c $(libft_DIR) clean
	rm -rf $(OBJ)

#-----------------------------------------------------------------------------------------

#											On Linux :

# $(NAME): $(OBJ)
# #	make -c $(libft_DIR)
#  	make -C mlx_Linux 
# 	$(CC) $(CFLAGS) $(OBJ) -Lmlx_Linux -l:libmlx_Linux.a -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) $(libft)

# %.o: %.c main.h $(libft_DIR)/libft.h
# 	$(CC) $(CFLAGS)  -I/usr/include -Imlx_linux -O3 -c $< -o $@

# clean: 
# #	make -c $(libft_DIR) clean
# 	make -C mlx_Linux  clean
# 	rm -rf $(OBJ)

#-----------------------------------------------------------------------------------------

fclean: clean
#	make -c $(libft_DIR) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re