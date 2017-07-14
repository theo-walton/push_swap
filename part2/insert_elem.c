/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 23:29:17 by twalton           #+#    #+#             */
/*   Updated: 2017/07/10 23:29:17 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_ind(int *brr)
{
	int i;
	int max;
	int max_ind;

	i = 1;
	max_ind = 1;
	max = brr[1];
	while (i <= brr[0])
	{
		if (brr[i] > max)
		{
			max = brr[i];
			max_ind = i;
		}
		i++;
	}
	return (max_ind);
}

static int	b_index(int *brr, int x)
{
	int max;
	int max_ind;
	int i;
	int toggle;

	i = 1;
	toggle = 0;
	max = brr[1];
	while (i <= brr[0])
	{
		if (brr[i] < x && brr[i] > max)
		{
			toggle = 1;
			max = brr[i];
			max_ind = i;
		}
		i++;
	}
	if (!toggle)
		max_ind = get_max_ind(brr);
	return (max_ind);
}

static void	take_note_of_ops2(int *op_arr, int *b_rot, int i)
{
	int toggle;
	int temp;

        toggle = 0;
	if (b_rot[0] < b_rot[1])
		temp = b_rot[0];
	else
		temp = b_rot[1];
	while (temp--)
		op_arr[i++] = 11;
	if (b_rot[0] > b_rot[1])
		temp = b_rot[0] - b_rot[1];
	else
	{
		toggle = 1;
		temp = b_rot[1] - b_rot[0];
	}
	while (temp--)
		op_arr[i++] = 9 + toggle;
}

static void	take_note_of_ops(int *op_arr, int *f_rot, int *b_rot)
{
	int i;
	int temp;
	int toggle;

	toggle = 0;
	i = 0;
	while (op_arr[i])
		i++;
	if (f_rot[0] < f_rot[1])
		temp = f_rot[0];
	else
		temp = f_rot[1];
	while (temp--)
		op_arr[i++] = 8;
	if (f_rot[0] > f_rot[1])
		temp = f_rot[0] - f_rot[1];
	else
	{
		toggle = 1;
		temp = f_rot[1] - f_rot[0];
	}
	while (temp--)
		op_arr[i++] = 6 + toggle;
	take_note_of_ops2(op_arr, b_rot, i);
}

void	insert_elem(int *arr, int *brr, int i, int *op_arr)
{
	int f_rot[2];
	int b_rot[2];
	int j;

	if ((f_rot[0] = 0) || (f_rot[1] = 0) || (b_rot[0] = 0) || (b_rot[1] = 0))
		return ;
	if (i > (arr[0] + 1) / 2)
		f_rot[0] = arr[0] - i + 1;
	else
		b_rot[0] = i - 1;
	j = b_index(brr, arr[i]);
	if (j > (brr[0] + 1) / 2)
		f_rot[1] = brr[0] - j + 1;
	else
		b_rot[1] = j - 1;
	take_note_of_ops(op_arr, f_rot, b_rot);
	rot_n(arr, f_rot[0], b_rot[0]);
	rot_n(brr, f_rot[1], b_rot[1]);
	push_elem(brr, arr);
	j = 0;
	while (op_arr[j])
		j++;
	op_arr[j] = 5;
}
