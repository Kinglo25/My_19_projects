NAME = cub3D

MLX = -I./usr/local/include/ -L/usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

SRCS = 

OBJS = $(SRCS:c=o)

FLAGS = -Wall -Wextra -Werror

%.o: %.c
    $(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
    $(CC) -Lmlx_linux -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)