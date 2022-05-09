# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 17:34:27 by lmajerus          #+#    #+#              #
#    Updated: 2022/04/14 20:03:10 by lmajerus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ImNoLoser

SRCS		=	main.cpp

OBJS		=	$(SRCS:cpp=o)

CC			=	clang++

FLAGS		=	-Wall -Wextra -Werror -std=c++98

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

dirty	:	$(NAME)

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
		./ImNoLoser test Coucou Salut; cat test; cat test.replace
		@echo "\n\033[0;31mTest:\033[0m"
		./ImNoLoser test "ca va ?" "petite perruche !"; cat test; cat test.replace

.PHONY: all clean fclean re