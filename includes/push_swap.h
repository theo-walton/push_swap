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

int	*get_array(int ac, char **av);
void	push_elem(int *arr, int *brr);
void	rot_elem(int *arr, char sign);
void	swap_elem(int *arr);
char	**get_actions(int *arr);
void	combine_actions(int *op_arr);
void	bubble_sort(int *arr, int *op_arr, char stack);
void	combine_sorted_arrays(int *arr, int *brr, int *op_arr);
int	is_sort(int *arr);
void	push_half_arr_into_brr(int *arr, int *brr, int *op_arr);
int	*sort_arr(int *arr);
void	free_strarr(char **strarr);
void	put_actions(char **strarr);

#endif
