
#--------------------------   On Mac :


# CC = cc
# CFLAGS = -Wall -Wextra -Werror

# SRC = ./Mandatory/main.c ./Mandatory/arguments.c ./Mandatory/initialize.c ./Mandatory/render.c ./Mandatory/events.c ./Mandatory/utils.c

# OBJC = $(SRC:.c=.o)

# B_SRC = ./Bonus/main.c ./Bonus/arguments.c ./Bonus/initialize.c ./Bonus/render.c ./Bonus/events.c ./Bonus/utils.c

# B_OBJC = $(B_SRC:.c=.o)

# libft_D = ./42_Libft
# libft = $(libft_D)/libft.a

# M_check= /tmp/M.check
# B_check= /tmp/B.check

# NAME= ./fractol

# all: $(NAME)

# $(NAME): $(OBJC) $(M_check) 
# 	make -C $(libft_D)
# 	$(CC) $(CFLAGS) $(OBJC) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(libft)

# $(M_check):
# 	touch $(M_check)
# 	rm -rf $(B_check)

# bonus: $(B_OBJC) $(B_check) 
# 	make -C $(libft_D)
# 	$(CC) $(CFLAGS) $(B_OBJC) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(libft)

# $(B_check):
# 	touch $(B_check)
# 	rm -rf $(M_check)

# %.o: %.c ./main.c $(libft_DIR)/libft.h
# 	$(CC) $(CFLAGS) -Imlx -c $< -o $@


# clean:
# 	make -C $(libft_D) clean
# 	rm -rf $(OBJC)
# 	rm -rf $(B_OBJC)

# fclean: clean
# 	make -C $(libft_D) fclean
# 	rm -rf $(NAME)
# 	rm -rf $(M_check)
# 	rm -rf $(B_check)

# re: fclean all

# .PHONY: all bonus clean fclean






#--------------------------   On Linux :


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
	$(CC) $(CFLAGS) $(OBJC) -Lmlx_Linux -l:libmlx_Linux.a -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) $(libft)

$(M_check):
	touch $(M_check)
	rm -rf $(B_check)

bonus: $(B_OBJC) $(B_check) 
	make -C $(libft_D)
	$(CC) $(CFLAGS) $(B_OBJC) -Lmlx_Linux -l:libmlx_Linux.a -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) $(libft)

$(B_check):
	touch $(B_check)
	rm -rf $(M_check)

%.o: %.c ./main.c $(libft_DIR)/libft.h
	$(CC) $(CFLAGS) -Imlx_linux -O3 -c $< -o $@

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
