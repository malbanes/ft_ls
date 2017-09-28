# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malbanes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/13 18:29:34 by malbanes          #+#    #+#              #
#    Updated: 2017/09/23 16:33:07 by malbanes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_ls

SRCDIR = srcs/

SRC= *.c

OBJ=$(SRC:.c=.o)

INCS=srcs/ls.h

FLAGS = -Wall -Wextra -Werror -g

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) libft/libft.a $^

$(OBJ): $(SRCDIR)$(SRC) $(INCS)
	make -C libft
	gcc -c libft/libft.h $^

clean:
	make clean -C libft
	rm $(OBJ)

fclean: clean
	make fclean -C libft
	rm $(NAME)

re: fclean all
	make re -C libft
