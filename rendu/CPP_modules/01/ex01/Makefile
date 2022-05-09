# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 17:52:53 by lmajerus          #+#    #+#              #
#    Updated: 2022/04/14 15:50:49 by lmajerus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ZombabiesHorde

SRCS		=	main.cpp \
				Zombies.cpp \
				zombie_horde.cpp

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
		./ZombabiesHorde 3 "A bunch of Zombabies"
		@echo "\n\033[0;31mTest:\033[0m"
		expr `./ZombabiesHorde 42 "How many are we?" | wc -l` / 2
		@echo "\n\033[0;31mTest:\033[0m"
		valgrind ./ZombabiesHorde 3 "Does everyone's head explode ?"


.PHONY: all clean fclean re