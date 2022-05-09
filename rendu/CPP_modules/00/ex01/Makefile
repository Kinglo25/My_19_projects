NAME		=	MyHappyPhoneBook

SRCS		=	main.cpp src/PhoneBook.cpp src/Contact.cpp

INC			=	-I inc/

OBJS		=	$(SRCS:cpp=o)

CC			=	clang++

FLAGS	=	-Wall -Wextra -Werror -std=c++98

RM			=	rm -f

all :		$(NAME)

%.o :		%.cpp
		@echo "\n\033[0;33mCompiling $<"
		@$(CC) $(INC) $(FLAGS) -c $< -o $(<:cpp=o)
		@echo "\n\033[0;33mCompiling OK!\033[0m"

$(NAME) :	$(OBJS)
		@echo "\n\033[0;33mCreating an executable"
		@$(CC) $(CFLAGS) $^ -o $@
		@echo "\n\033[0;33mJob's done!\033[0m"

clean:
		@echo "\033[0;31mCleaning objects..."
		@rm -rf $(OBJS)
		@echo "Cleaned up!\033[0m"
	
fclean:		clean
		@echo "\033[0;31mRemoving executable..."
		@rm -f $(NAME)
		@echo "Removed!\033[0m"

re: 		fclean all

.PHONY: all clean fclean re