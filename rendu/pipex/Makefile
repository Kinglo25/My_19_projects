NAME	=	pipex

SRCS	=	srcs/cmd.c srcs/error.c srcs/pipex.c  \
			srcs/utils.c srcs/utils1.c

OBJS	=	$(SRCS:c=o)

INC		=	-I inc/

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror

all :		$(NAME)

%.o :		%.c
		@echo "\n\033[0;33mCompiling $<"
		@$(CC) $(INC) $(FLAGS) -c $< -o $(<:c=o)
		@echo "\n\033[0;33mCompiling OK!"

$(NAME) :	$(OBJS)
		@echo "\n\033[0;33mCreating an executable"
		@$(CC) $(INC) $(CFLAGS) $^ -o $@
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