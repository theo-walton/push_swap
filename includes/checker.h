/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 17:45:39 by twalton           #+#    #+#             */
/*   Updated: 2017/07/05 17:45:39 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

# define MINT (-2147483648)

char	**check_valid(char **strarr);
void    does_solve(char **strarr, int *arr);
int	*get_array(int ac, char **av);
void	push_elem(int *arr, int *brr);
char	**read_input(void);
void	rot_elem(int *arr, char sign);
void	swap_elem(int *arr);
int	*get_single_arg_arr(char *str);

#endif
