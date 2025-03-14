CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ./Mandatory/main.c ./Mandatory/arguments.c ./Mandatory/initialize.c ./Mandatory/render.c ./Mandatory/events.c ./Mandatory/utils.c

OBJC = $(SRC:.c=.o)

B_SRC = ./Bonus/main.c ./Bonus/arguments.c ./Bonus/initialize.c ./Bonus/render.c ./Bonus/events.c ./Bonus/utils.c

B_OBJC = $(B_SRC:.c=.o)

libft_D = ./42_Libft
libft = $(libft_D)/libft.a

M_check= /tmp/M.check
B_check= /tmp/B.check

NAME= ./fractol

all: $(NAME)

$(NAME): $(OBJC) $(M_check) 
	make -C $(libft_D)
	$(CC) $(CFLAGS) $(OBJC) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(libft)

$(M_check):
	touch $(M_check)
	rm -rf $(B_check)

bonus: $(B_OBJC) $(B_check) 
	make -C $(libft_D)
	$(CC) $(CFLAGS) $(B_OBJC) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(libft)

$(B_check):
	touch $(B_check)
	rm -rf $(M_check)

%.o: %.c ./main.c $(libft_DIR)/libft.h
	$(CC) $(CFLAGS) -Imlx -c $< -o $@


clean:
	make -C $(libft_D) clean
	rm -rf $(OBJC)
	rm -rf $(B_OBJC)

fclean: clean
	make -C $(libft_D) fclean
	rm -rf $(NAME)
	rm -rf $(M_check)
	rm -rf $(B_check)

re: fclean all

.PHONY: all bonus clean fclean





# CC = cc
# # CFLAGS = -Wall -Werror -Wextra
# # CFLAGS = -Wall -fsanitize=address 
# CFLAGS = -Wall

# # SRC = a.c r.c
# # SRC = ./Mandatory/main.c ./Mandatory/initialize.c ./Mandatory/arguments.c ./Mandatory/render.c ./Mandatory/events.c ./Mandatory/utils.c
# SRC = ./Bonus/main.c ./Bonus/initialize.c ./Bonus/arguments.c ./Bonus/render.c ./Bonus/events.c ./Bonus/utils.c


# OBJ = $(SRC:.c=.o)

# # includs = main.h
# includs = /Bonus/main.h


# libft_DIR = ./42_Libft
# libft = $(libft_DIR)/libft.a

# NAME = fractol

# all: $(NAME) clean

# #-----------------------------------------------------------------------------------------

# #											On Mac :

# $(NAME): $(OBJ)
# #	make -C $(libft_DIR)
# #	make -C mlx
# 	$(CC) $(CFLAGS) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(libft)

# %.o: %.c $(includs) $(libft_DIR)/libft.h
# 	$(CC) $(CFLAGS) -Imlx -c $< -o $@

# clean: 
# #	make -C $(libft_DIR) clean
# 	rm -rf $(OBJ)

# #-----------------------------------------------------------------------------------------

# #											On Linux :

# # $(NAME): $(OBJ)
# # #	make -C $(libft_DIR)
# # 	make -C mlx_Linux
# # 	$(CC) $(CFLAGS) $(OBJ) -Lmlx_Linux -l:libmlx_Linux.a -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) $(libft)

# # %.o: %.c $(includs) $(libft_DIR)/libft.h
# # 	$(CC) $(CFLAGS)  -I/usr/include -Imlx_linux -O3 -c $< -o $@

# # clean: 
# # #	make -C $(libft_DIR) clean
# # #	make -C mlx_Linux  clean
# # 	rm -rf $(OBJ)

# #-----------------------------------------------------------------------------------------

# fclean: clean
# #	make -C $(libft_DIR) fclean
# 	rm -rf $(NAME)

# re: fclean all

# .PHONY: all clean fclean re


