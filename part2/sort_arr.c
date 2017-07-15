/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 23:19:43 by twalton           #+#    #+#             */
/*   Updated: 2017/07/05 23:19:43 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	makezero(int *op_arr)
{
	int i;

	i = 0;
	while (i < 100000)
		op_arr[i++] = 0;
}

int			*sort_arr(int *arr)
{
	int *brr;
	int *op_arr;

	if (!(op_arr = malloc(sizeof(int) * (100000))))
		return (NULL);
	makezero(op_arr);
	if (!(brr = malloc(sizeof(int) * (arr[0] + 1))))
		return (NULL);
	brr[0] = 0;
	if (!brute_force(arr, brr, op_arr))
	{
		makezero(op_arr);
		insersion_sort(arr, brr, op_arr);
	}
	return (op_arr);
}
