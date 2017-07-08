/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine_sorted_arrays.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 20:51:06 by twalton           #+#    #+#             */
/*   Updated: 2017/07/07 20:51:06 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	combine_sorted_arrays(int *arr, int *brr, int *op_arr)
{
	while (brr[0] != 0)
	{
		while (arr[1] < brr[1])
		{
			rot_elem(arr, "-");
			op_arr[op_arr[0] + 1] = 5;
			++op_arr[0];
		}
		while (arr[1] > brr[1])
		{
			push_elem(arr, brr);
			op_arr[op_arr[0] + 1] = 8;
			++op_arr[0];
		}
	}
}
