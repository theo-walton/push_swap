/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rot_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 16:01:31 by twalton           #+#    #+#             */
/*   Updated: 2017/07/14 16:01:31 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_rot_sort(int *arr)
{
	int i;

	i = 1;
	while (i < arr[0])
	{
		if (arr[i] > arr[i + 1])
			break;
		++i;
	}
	++i;
	while (i <= arr[0])
	{
		if (i == arr[0])
		{
			if (arr[i] > arr[1])
				return (0);
			return (1);
		}
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}
