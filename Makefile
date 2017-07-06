# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: twalton <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/05 17:53:01 by twalton           #+#    #+#              #
#    Updated: 2017/07/05 17:53:02 by twalton          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tester

SRC = checker.c does_solve.c push_elem.c rot_elem.c check_valid.c get_array.c \
read_input.c swap_elem.c libft/ft_isdigit.c libft/ft_atoi.c libft/ft_strsplit.c \
libft/ft_createstr.c libft/ft_strcmp.c libft/ft_strnew.c libft/ft_strlen.c \
libft/ft_strcpy.c libft/ft_bzero.c libft/ft_memset.c

OBJ = *.o

HEADERS = -I .

all: $(NAME)

$(NAME):
	cp libft/includes/libft.h .
	gcc -Wfatal-errors -Wall -Wextra -Werror -c $(SRC) $(HEADERS)
	gcc $(OBJ) -o tester
	rm libft.h

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all