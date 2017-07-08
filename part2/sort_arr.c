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

static void	create_seperator(int *op_arr)
{
	op_arr[op_arr[0] + 1] = -1;
	op_arr[0]++;
}

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
	create_seperator(op_arr);
	bubble_sort(arr, op_arr, 'a');
	create_seperator(op_arr);
	bubble_sort(brr, op_arr, 'b');
	create_seperator(op_arr);
	combine_actions(op_arr);
	combine_sorted_arrays(arr, brr, op_arr);
	return (op_arr);
}
