/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 02:31:47 by twalton           #+#    #+#             */
/*   Updated: 2017/07/06 02:31:47 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	rot_n_times(int *arr, int *op_arr, char sign, char stack)
{
	while (arr[1] < arr[2])
	{
		rot_elem(arr, sign);
		if (sign == '+')
		{
			op_arr[op_arr[0] + 1] = (stack - 'a') * 2 + 4;
			op_ar[0]++;
		}
		else
		{
			op_arr[op_arr[0] + 1] = (stack - 'a') * 2 + 5;
			op_arr[0]++;
		}
	}
}

static void	find_elems_to_swap(int *arr, int *op_arr, char stack)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	while (arr[1] < arr[2] && i++ != -1)
		rot_elem(arr, '+');
	x = i;
	while (i-- > 0)
		rot_elem(arr, '-');
	while (arr[1] < arr[2] && i++ != -1)
		rot_elem(arr, '-');
	y = i;
	while (i-- > 0)
		rot_elem(arr, '+');
	if (y <= x)
		rot_n_times(arr, op_arr, '-', stack);
	else
		rot_n_times(arr, op_arr, '+', stack);
}

void	bubble_sort(int *arr, int *op_arr, char stack)
{
	while (!is_sort(arr))
	{
		find_elems_to_swap(arr, op_arr, stack);
		swap_elem(arr);
		op_arr[op_arr[0] + 1] = (stack - 'a') + 2;
		op_arr[0]++;
	}
}
