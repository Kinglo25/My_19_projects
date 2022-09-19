NAME	=	cub3D

MLX		=	-I./usr/local/include/ -L/usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

SRCS	=	srcs/get_map.c srcs/get_next_line.c srcs/get_RFC.c \
		srcs/get_textures.c srcs/parser.c srcs/utils.c srcs/main.c \
		srcs/mlx.c srcs/raycasting.c srcs/utils2.c \
		srcs/event.c srcs/move.c srcs/draw.c

OBJS	=	$(SRCS:c=o)

INC		= -I.

CC		= 	gcc

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

%.o:		%.c
		@echo "Compiling $<"
		@$(CC) $(CFLAGS) -c $(INC) $< -o $(<:c=o)
		@echo "Compiling OK!"

$(NAME) :	$(OBJS)
		@echo "\n\033[0;33mCreating an executable"
		@$(CC) $(INC) $(CFLAGS) $(MLX) $^ -o $@
		@echo "\n\033[0;33mJob's done!"

clean:
		@echo "\033[0;31mCleaning objects..."
		@rm -rf $(OBJS)
		@echo "Cleaned up!\033[0m"
	
fclean:		clean
		@echo "\033[0;31mRemoving executable..."
		@rm -f $(NAME)
		@echo "Removed!\033[0m"

re: fclean all

.PHONY: all clean fclean re