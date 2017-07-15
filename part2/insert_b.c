/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 11:43:21 by twalton           #+#    #+#             */
/*   Updated: 2017/07/11 11:43:21 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min_ind(int *brr)
{
	int i;
	int min;
	int min_ind;

	i = 1;
	min_ind = 1;
	min = brr[1];
	while (i <= brr[0])
	{
		if (brr[i] < min)
		{
			min = brr[i];
			min_ind = i;
		}
		i++;
	}
	return (min_ind);
}

static int	find_index_to_rot(int *brr, int x)
{
	int min;
	int min_ind;
	int i;
	int toggle;

	i = 1;
	toggle = 0;
	min = MAXT;
	while (i <= brr[0])
	{
		if (brr[i] > x && brr[i] < min)
		{
			toggle = 1;
			min = brr[i];
			min_ind = i;
		}
		i++;
	}
	if (!toggle)
		min_ind = get_min_ind(brr);
	return (min_ind);
}

void		insert_b(int *arr, int *brr, int *op_arr)
{
	int index;
	int i;

	i = 0;
	while (op_arr[i])
		i++;
	index = find_index_to_rot(arr, brr[1]);
	if (index > (arr[0] + 1) / 2)
	{
		while (index++ <= arr[0])
		{
			rot_elem(arr, '+');
			op_arr[i++] = 6;
		}
	}
	else
	{
		while (index-- > 1)
		{
			rot_elem(arr, '-');
			op_arr[i++] = 9;
		}
	}
	push_elem(arr, brr);
	op_arr[i] = 4;
}
