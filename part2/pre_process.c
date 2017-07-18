/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 22:59:05 by twalton           #+#    #+#             */
/*   Updated: 2017/07/17 22:59:05 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_seperator(int *arr, int top, int bot)
{
	int tarr[arr[0]];
	int counter;

	ft_memcpy(tarr, arr + 1, sizeof(int) * arr[0]);
	ft_sort(tarr, arr[0]);
	counter = (arr[0] * top) / bot;
	return (tarr[counter]);
}

static void	push_or_rot(int *arr, int *brr, int *op_arr, int *seperator)
{
	int i;

	i = 0;
	while (op_arr[i])
		i++;
	if (arr[1] < seperator[0])
	{
		push_elem(brr, arr);
		op_arr[i++] = 5;
		rot_elem(brr, '-');
		op_arr[i++] = 10;
	}
	else if (arr[1] >= seperator[0] && arr[1] < seperator[1])
	{
		push_elem(brr, arr);
		op_arr[i++] = 5;
	}
	else if (arr[1] >= seperator[1])
	{
		rot_elem(arr, '-');
		op_arr[i++] = 9;
	}
}

void		pre_process(int *arr, int *brr, int *op_arr)
{
	int seperator[2];
	int i;

	seperator[0] = find_seperator(arr, 1, 3);
	seperator[1] = find_seperator(arr, 2, 3);
	i = arr[0];
	while (i--)
		push_or_rot(arr, brr, op_arr, seperator);
	i++;
	while (op_arr[i])
		++i;
	while (brr[0])
	{
		push_elem(arr, brr);
		op_arr[i++] = 4;
	}
}
