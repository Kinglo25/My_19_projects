NAME		=	push_swap

SRCS		=	main.c push.c rotate.c sort_small_stacks.c \
				utils.c free_exit.c index.c parser.c \
				reverse_rotate.c sort_big_stacks.c swap.c 

OBJS		=	$(SRCS:c=o)

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -g

INC			=	-I ../includes

all:		$(OBJS) $(NAME)

%.o:		%.c
				@echo "Compiling $<"
				@$(CC) $(CFLAGS) -c $(INC) $< -o $(<:c=o)
				@echo "Compiling OK!"

$(NAME):	$(OBJS)
				@echo "compiling $<"
				@cc $(CFLAGS) $^ -o $@ 
clean:
				@echo "Cleaning objects..."
				@rm -f $(OBJS) $(BONUS_OBJS)
				@echo "Cleaned up!"

fclean:		clean
				@echo "Cleaning..."
				@rm -f $(NAME)
				@echo "Cleaned up!"

re:			fclean all

.PHONY:		all clean fclean re