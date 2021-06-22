# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/14 15:38:41 by ssamadi           #+#    #+#              #
#    Updated: 2021/06/20 17:11:17 by ssamadi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

FLAGS = -Wall -Wextra -Werror

SRC = src/main.c src/norm_file1.c \
src/norm_file_2.c src/norm_file_3.c \
src/norm_file_4.c src/norm_file_5.c \
src/norm_file_6.c src/my_atoi.c \
src/norm_file_7.c \
src/norm_file_8.c \
src/norm_file_9.c 

SRC_BONUS = src_bonus/main_bonus.c \
src_bonus/my_atoi_bonus.c \
src_bonus/norm_file1_bonus.c \
src_bonus/norm_file_2_bonus.c \
src_bonus/norm_file_3_bonus.c \
src_bonus/norm_file_5_bonus.c \
src_bonus/norm_file_7_bonus.c src_bonus/norm_file_8_bonus.c \
src_bonus/norm_file_9_bonus.c \
src_bonus/get_next_line_bonus.c

CC = gcc

all: libft1 $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(SRC)
	cd libft1 && $(MAKE)
	cp ./libft1/libft.a .
	$(CC) $(FLAGS) $(SRC) libft.a -o $(NAME)

$(NAME_BONUS): $(SRC_BONUS)
	cd libft1 && $(MAKE)
	cp ./libft1/libft.a .
	$(CC) $(FLAGS) $(SRC_BONUS) libft.a -o $(NAME_BONUS)

libft1:
	cd libft1 && $(MAKE) clean

clean: libftclean

libftclean:
	$(MAKE)	-C libft1/ clean

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS) libft.a  libft1/libft.a
	
re: fclean all