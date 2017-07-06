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

static void	makezero(int *op_arr)
{
	int i;

	i = 0;
	while (i < 100000)
		op_arr[i++] = 0;
}

int	*sort_arr(int *arr)
{
	int *brr;
	int *op_arr;

	if (!(op_arr = malloc(sizeof(int) * (100000))))
		return (NULL);
	makezero(op_arr);
	if (!(brr = malloc(sizeof(int) * (arr[0] + 1))))
		return (NULL);
	brr[0] = 0;
	push_half_arr_into_brr(arr, brr, op_arr);
	bubble_sort(arr, op_arr);
	bubble_sort(brr, op_arr);
	combine_actions(op_arr);
	combine_sorted_arrays(arr, brr, op_arr);
	return (op_arr);
}
