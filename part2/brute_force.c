/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute_force.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 22:32:38 by twalton           #+#    #+#             */
/*   Updated: 2017/07/08 22:32:38 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_next_ops(int *op_arr)
{
	int i;

	i = 0;
	while (op_arr[i] == 11)
		i++;
	op_arr[i]++;
	while (i > 0)
		op_arr[--i] = 1;
}

int	brute_force(int *arr, int *brr, int *op_arr)
{
	int i;

	i = 0;
	while (!will_solve(arr, brr, op_arr) && i++ < 1771561)
	{
		brr[0] = 0;
		get_next_ops(op_arr);
	}
	if (i >= 1771560)
	{
		brr[0] = 0;
		return (0);
	}
	return (1);
}
