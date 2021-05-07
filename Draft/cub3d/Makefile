NAME =	cub3D

MLX =	-I./usr/local/include/ -L/usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

SRCS =	srcs/get_map.c srcs/get_next_line.c srcs/get_RFC.c \
		srcs/get_textures.c srcs/parser.c srcs/utils.c

OBJS = $(SRCS:c=o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
		@echo "\n\033[0;33mCompiling..."
		$(CC) -o $(NAME) $(OBJS)

clean :
		@echo "\033[0;31mCleaning objects..."
		@rm -rf $(OBJS)
		@echo "Cleaned up!\033[0m"
	
fclean :
		@echo "\033[0;31mRemoving executable..."
		@rm -f $(NAME)
		@echo "Removed!\033[0m"

re : fclean all

.PHONY: all clean fclean re