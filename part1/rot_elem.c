/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 22:34:22 by twalton           #+#    #+#             */
/*   Updated: 2017/07/04 22:34:22 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rot_elem(int *arr, char sign)
{
	int i;
	int temp;

	if (sign == '-')
	{
		i = 1;
		temp = arr[i];
		while (i < arr[0])
		{
			arr[i] = arr[i + 1];
			++i;
		}
		arr[i] = temp;
	}
	else
	{
		i  = arr[0];
		temp = arr[i];
		while (i > 1)
		{
			arr[i] = arr[i - 1];
			--i;
		}
		arr[i] = temp;
	}
}
