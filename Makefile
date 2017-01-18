# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmihalac <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/10 15:00:20 by nmihalac          #+#    #+#              #
#    Updated: 2017/01/13 12:57:33 by pcervac          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

CC=cc
CFLAGS=-Wall -Wextra -Werror
SRC=./ft_stdlib/*.c ./ft_stdio/*.c	./ft_string/*.c \
	./ft_ctype/*.c 	./ft_list/*.c	./ft_wchar/*.c	\
	./ft_printf/*.c	./ft_cllist/*.c
NAME=libft.a
INC_PATH=.
OBJ=*.o

all: $(NAME)

$(NAME):
	@echo -n 'Creating library ... '
	@$(CC) $(CFLAGS) -c $(SRC) -I $(INC_PATH)
	@ar rc $(NAME)  *.o
	@ranlib $(NAME)
	@echo '[done]'

clean:
	@echo -n 'Removing objects ... '
	@/bin/rm -rf *.o
	@echo '[done]'

fclean: clean
	@echo -n 'Removing library ... '
	@/bin/rm -rf $(NAME)
	@echo '[done]'

re: fclean all

n:
	@norminette $(SRC) *.h
.PHONY: clean
