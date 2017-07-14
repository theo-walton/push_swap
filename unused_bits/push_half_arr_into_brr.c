/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_half_arr_into_brr.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 02:24:53 by twalton           #+#    #+#             */
/*   Updated: 2017/07/06 02:24:53 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	push_half_arr_into_brr(int *arr, int *brr, int *op_arr)
{
	
	while (arr[0] - brr[0] > 1)
	{
		push_elem(brr, arr);
		op_arr[op_arr[0] + 1] = 1;
		op_arr[0]++;
		printf("%d, %d : %d, %d\n", arr[0], brr[0], arr[1], brr[1]);
	}
}
