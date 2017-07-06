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

NAME = checker

SRC = part1/checker.c part1/does_solve.c part1/push_elem.c part1/rot_elem.c part1/check_valid.c \
part1/get_array.c part1/read_input.c part1/swap_elem.c libft/ft_isdigit.c libft/ft_atoi.c \
libft/ft_strsplit.c libft/ft_createstr.c libft/ft_strcmp.c libft/ft_strnew.c libft/ft_strlen.c \
libft/ft_strcpy.c libft/ft_bzero.c libft/ft_memset.c

OBJ = objects/*.o

HEADERS = -I includes/.

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC) $(HEADERS)
	mv *.o objects
	gcc $(OBJ) -o $(NAME)

clean:
	rm -rf objects/*.o

fclean: clean
	rm -rf $(NAME)

re: fclean all