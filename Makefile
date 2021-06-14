# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/14 15:38:41 by ssamadi           #+#    #+#              #
#    Updated: 2021/06/14 17:58:46 by ssamadi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

FLAGS = -Wall -Wextra -Werror

SRC = src/main.c src/norm_file1.c \
src/norm_file_2.c src/norm_file_3.c \
src/norm_file_4.c src/norm_file_5.c \
src/norm_file_6.c src/my_atoi.c \
src/norm_file_7.c \
src/norm_file_8.c \
src/norm_file_9.c 

CC = gcc

all: libft1 $(NAME)

$(NAME): $(SRC)
	cp ./libft1/libft.a .
	$(CC) $(FLAGS) $(SRC) libft.a -o $(NAME)

libft1:
	cd libft && $(MAKE) clean

clean: libftclean

libftclean:
	$(MAKE)	-C libft1/ clean

fclean: clean
	rm -rf $(NAME) libft.a 
	
re: fclean all