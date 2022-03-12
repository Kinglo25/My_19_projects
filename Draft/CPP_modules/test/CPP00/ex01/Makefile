# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jandre <jandre@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/28 13:16:26 by jandre            #+#    #+#              #
#    Updated: 2021/07/29 13:58:04 by jandre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lame_phone_book

CC = clang++

CFLAGS = -Wall -Wextra -Werror

SRC = lamephonebook.cpp main.cpp contact.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

.cpp.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean