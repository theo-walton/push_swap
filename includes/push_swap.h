/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 21:52:05 by twalton           #+#    #+#             */
/*   Updated: 2017/07/07 21:52:05 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

# define MINT (-2147483648)
# define MAXT (2147483647)

int	*get_array(int ac, char **av);
int	*get_single_arg_arr(char *str);
void	push_elem(int *arr, int *brr);
void	rot_elem(int *arr, char sign);
void	swap_elem(int *arr);
char	**get_actions(int *arr);
int	is_sort(int *arr);
int	*sort_arr(int *arr);
void	free_strarr(char **strarr);
void	put_actions(char **strarr);
int	brute_force(int *arr, int *brr, int *op_arr);
int	will_solve(int *arr, int *brr, int *op_arr);
void	insersion_sort(int *arr, int *brr, int *op_arr);
int	find_elem_to_insert(int *arr, int *brr);
void	insert_elem(int *arr, int *brr, int i, int *op_arr);
void	insert_b(int *arr, int *brr, int *op_arr);
void	rot_n(int *arr, int f_rot, int b_rot);
int	is_rot_sort(int *arr);

#endif
