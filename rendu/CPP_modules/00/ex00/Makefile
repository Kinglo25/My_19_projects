NAME		=	megaphone

SRCS		=	megaphone.cpp

OBJS		=	$(SRCS:cpp=o)

CC			=	clang++

FLAGS	=	-Wall -Wextra -Werror -std=c++98

RM			=	rm -f

all :		$(NAME)

%.o :		%.cpp
		@echo "\n\033[0;33mCompiling $<"
		@$(CC) $(FLAGS) -c $< -o $(<:cpp=o)
		@echo "\n\033[0;33mCompiling OK!"

$(NAME) :	$(OBJS)
		@echo "\n\033[0;33mCreating an executable"
		@$(CC) $(CFLAGS) $^ -o $@
		@echo "\n\033[0;33mJob's done!"

clean:
		@echo "\033[0;31mCleaning objects..."
		@rm -rf $(OBJS)
		@echo "Cleaned up!\033[0m"
	
fclean:		clean
		@echo "\033[0;31mRemoving executable..."
		@rm -f $(NAME)
		@echo "Removed!\033[0m"

re: 		fclean all

test:		re
		@echo "\n\033[0;31mTest:\033[0m"
		./megaphone "shhhhh... I think the students are asleep..."
		@echo "\n\033[0;31mTest:\033[0m"
		./megaphone Damnit " ! " "Sorry students, I thought this thing was off." 
		@echo "\n\033[0;31mTest:\033[0m"
		./megaphone

.PHONY: all clean fclean re