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

NAME1 = checker

NAME2 = push_swap

SRC1 = part1/checker.c part1/does_solve.c part1/push_elem.c part1/rot_elem.c part1/check_valid.c \
part1/get_array.c part1/read_input.c part1/swap_elem.c libft/ft_isdigit.c libft/ft_atoi.c \
libft/ft_strsplit.c libft/ft_createstr.c libft/ft_strcmp.c libft/ft_strnew.c libft/ft_strlen.c \
libft/ft_strcpy.c libft/ft_bzero.c libft/ft_memset.c

SRC2 = part1/push_elem.c part1/rot_elem.c part2/bubble_sort.c part2/get_actions.c \
part1/get_array.c part1/swap_elem.c libft/ft_isdigit.c libft/ft_atoi.c \
libft/ft_strsplit.c libft/ft_strcmp.c libft/ft_strnew.c libft/ft_strlen.c \
libft/ft_strcpy.c libft/ft_bzero.c libft/ft_memset.c libft/ft_strdup.c \
part2/combine_actions.c	part2/is_sort.c	part2/sort_arr.c part2/combine_actions.c \
part2/push_half_arr_into_brr.c part2/combine_sorted_arrays.c part2/push_swap.c \
part2/free_strarr.c part2/put_actions.c libft/ft_putstr.c libft/ft_putstr_fd.c

OBJ = objects/*.o

HEADERS = -I includes/.

all: $(NAME1)

$(NAME1):
	gcc -Wall -Wextra -Werror -c $(SRC1) $(HEADERS)
	mv *.o objects
	gcc $(OBJ) -o $(NAME1)

2:
	gcc -Wall -Wextra -Werror -c $(SRC2) $(HEADERS)
	mv *.o objects
	gcc $(OBJ) -o $(NAME2)

clean:
	rm -rf objects/*.o

fclean: clean
	rm -rf $(NAME)

re: fclean all