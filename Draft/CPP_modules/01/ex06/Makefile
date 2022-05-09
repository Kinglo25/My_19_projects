# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 16:50:46 by lmajerus          #+#    #+#              #
#    Updated: 2022/04/06 16:52:49 by lmajerus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	FfsKarenStfuAlready

SRCS		=	main.cpp \
				Harl.cpp \

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
		./FfsKarenStfuAlready DEBUG
		@echo "\n\033[0;31mTest:\033[0m"
		./FfsKarenStfuAlready INFO
		@echo "\n\033[0;31mTest:\033[0m"
		./FfsKarenStfuAlready WARNING
		@echo "\n\033[0;31mTest:\033[0m"
		./FfsKarenStfuAlready ERROR
		@echo "\n\033[0;31mTest:\033[0m"
		./FfsKarenStfuAlready 
		@echo "\n\033[0;31mTest:\033[0m"
		./FfsKarenStfuAlready qwdqdas adlj ans
		@echo "\n\033[0;31mTest:\033[0m"
		./FfsKarenStfuAlready qwerty

.PHONY: all clean fclean re