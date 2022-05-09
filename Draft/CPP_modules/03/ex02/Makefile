# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/19 20:39:59 by lmajerus          #+#    #+#              #
#    Updated: 2022/04/20 00:34:58 by lmajerus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Action

SRCS		=	main.cpp \
				ClapTrap.cpp \
				ScavTrap.cpp \
				FragTrap.cpp

OBJS		=	$(SRCS:cpp=o)

CC			=	clang++

FLAGS		=	-Wall -Wextra -Werror -std=c++98

INC			=	

RM			=	rm -f

all :		$(NAME)

%.o :		%.cpp
		@echo "\n\033[0;33mCompiling $<"
		@$(CC) $(INC) $(FLAGS) -c $< -o $(<:cpp=o)
		@echo "\n\033[0;33mCompiling OK!\033[0m"

$(NAME) :	$(OBJS)
		@echo "\n\033[0;33mCreating an executable"
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


.PHONY: all clean fclean re