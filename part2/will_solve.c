/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   will_solve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 23:18:04 by twalton           #+#    #+#             */
/*   Updated: 2017/07/08 23:18:04 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	perform_op2(int *arr, int *brr, int op)
{
	if (op == 8)
	{
		rot_elem(arr, '+');
		rot_elem(brr, '+');
	}
	if (op == 9)
		rot_elem(arr, '-');
	if (op == 10)
		rot_elem(brr, '-');
	if (op == 11)
	{
		rot_elem(arr, '-');
		rot_elem(brr, '-');
	}
}

static void	perform_op(int *arr, int *brr, int op)
{
	if (op == 1)
		swap_elem(arr);
	else if (op == 2)
		swap_elem(brr);
	else if (op == 3)
	{
		swap_elem(arr);
		swap_elem(brr);
	}
	else if (op == 4)
		push_elem(arr, brr);
	else if (op == 5)
		push_elem(brr, arr);
	else if (op == 6)
		rot_elem(arr, '+');
	else if (op == 7)
		rot_elem(brr, '+');
	else
		perform_op2(arr, brr, op);
}

static void	arr_cpy(int *arr, int *temp)
{
	int i;

	i = 0;
	while (i < arr[0] + 1)
	{
		temp[i] = arr[i];
		++i;
	}
}

static int	check_trivia(int *op_arr)
{
	int i;
	int arr[11];

	i = 0;
	while (i < 11)
		arr[i++] = 0;
	i = 0;
	while (op_arr[i])
		++arr[op_arr[i++] - 1];
	if (!arr[4] && (arr[3] || arr[2] || arr[6] ||
	arr[7] || arr[9] || arr[10]))
	{
		return (1);
	}
	if (arr[3] != arr[4])
		return (1);
	return (0);
}

int	will_solve(int *arr, int *brr, int *op_arr)
{
	int i;
	int temp[arr[0] + 1];

	arr_cpy(arr, temp);
	i = 0;
	if (check_trivia(op_arr))
		return (0);
	while (op_arr[i] != 0)
		perform_op(temp, brr, op_arr[i++]);
	if (!brr[0] && is_sort(temp))
		return (1);
	return (0);
}
