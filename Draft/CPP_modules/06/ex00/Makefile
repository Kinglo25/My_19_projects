# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/31 15:29:39 by lmajerus          #+#    #+#              #
#    Updated: 2022/06/01 15:56:49 by lmajerus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Conversion

SRCS		=	main.cpp \
				src/Conversion.cpp

OBJS		=	$(SRCS:cpp=o)

CC			=	clang++

FLAGS		=	-Wall -Wextra -Werror -std=c++98 

INC			=	-I./includes

RM			=	rm -f

all :		$(NAME)

%.o :		%.cpp
		@echo "\n\033[0;33mCompiling $<\033[0m"
		@$(CC) $(INC) $(FLAGS) -c $< -o $(<:cpp=o)
		@echo "\n\033[0;33mCompiling OK!\033[0m"

$(NAME) :	$(OBJS)
		@echo "\n\033[0;33mCreating an executable\033[0m"
		@$(CC) $(INC) $(CFLAGS) $^ -o $@
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

test: 
			./$(NAME) ""
			./$(NAME) "42"
			./$(NAME) "a423"
			./$(NAME) "-19.422f"
			./$(NAME) "+42.01919"
			./$(NAME) "90u23r0823"

			./$(NAME) "+inff"
			./$(NAME) "-inff"
			./$(NAME) "nanf"
			./$(NAME) "nan"
			./$(NAME) "+inf"
			./$(NAME) "-inf"

			./$(NAME) "-"
			./$(NAME) "+"

.PHONY: all clean fclean re