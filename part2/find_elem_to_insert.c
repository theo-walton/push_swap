/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_elem_to_insert.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 22:11:01 by twalton           #+#    #+#             */
/*   Updated: 2017/07/10 22:11:01 by twalton          ###   ########.fr       */
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
	max = MINT;
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

static int	rot_count(int *arr, int *brr, int i)
{
	int b_rot;
	int f_rot;
	int j;

	b_rot = 0;
	f_rot = 0;
	if (i > (arr[0] + 1) / 2)
		f_rot = arr[0] - i;
	else
		b_rot = i - 1;
	j = b_index(brr, arr[i]);
	if (j > (brr[0] + 1) / 2 && f_rot < brr[0] - j)
		f_rot = brr[0] - j;
	if (j <= (brr[0] + 1) / 2 && b_rot < j - 1)
		b_rot = j - 1;
	return (b_rot + f_rot);
}

int			find_elem_to_insert(int *arr, int *brr)
{
	int i;
	int best[2];

	best[1] = arr[0] + brr[0];
	i = 1;
	while (i < arr[0])
	{
		if (rot_count(arr, brr, i) < best[1])
		{
			best[0] = i;
			best[1] = rot_count(arr, brr, i);
		}
		++i;
	}
	return (best[0]);
}
