/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insersion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 23:36:09 by twalton           #+#    #+#             */
/*   Updated: 2017/07/09 23:36:09 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min_ind(int *arr)
{
	int i;
	int min;
	int min_ind;

	i = 1;
	min_ind = 1;
	min = arr[1];
	while (i <= arr[0])
	{
		if (arr[i] < min)
		{
			min = arr[i];
			min_ind = i;
		}
		i++;
	}
	return (min_ind);
}

static void	allign_a(int *arr, int *op_arr)
{
	int i;
	int k;

	k = 0;
	while (op_arr[k])
		k++;
	i = get_min_ind(arr);
	if (i > (arr[0] + 1) / 2)
	{
		while (i++ <= arr[0])
		{
			rot_elem(arr, '+');
			op_arr[k++] = 6;
		}
	}
	else
	{
		while (i-- > 1)
		{
			rot_elem(arr, '-');
			op_arr[k++] = 9;
		}
	}
}

static void	allign_b(int *brr, int *op_arr, int i, int k)
{
	int max[2];

	while (op_arr[i])
		i++;
	max[0] = brr[1];
	max[1] = 1;
	while (++k <= brr[0])
		if (max[0] < brr[k] && (max[1] = k))
			max[0] = brr[k];
	if (max[1] > (brr[0] + 1) / 2)
	{
		while (max[1]++ <= brr[0])
		{
			rot_elem(brr, '+');
			op_arr[i++] = 7;
		}
	}
	else
	{
		while (max[1]-- > 1)
		{
			rot_elem(brr, '-');
			op_arr[i++] = 10;
		}
	}
}

void		insersion_sort(int *arr, int *brr, int *op_arr)
{
	int index;

	index = 0;
	if (!is_rot_sort(arr))
	{
		push_elem(brr, arr);
		while (op_arr[index])
			index++;
		op_arr[index] = 5;
	}
	while (!is_rot_sort(arr))
	{
		index = find_elem_to_insert(arr, brr);
		insert_elem(arr, brr, index, op_arr);
	}
	if (brr[0])
		allign_b(brr, op_arr, 0, 0);
	while (brr[0])
		insert_b(arr, brr, op_arr);
	allign_a(arr, op_arr);
}
