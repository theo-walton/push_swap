/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_elem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 22:13:47 by twalton           #+#    #+#             */
/*   Updated: 2017/07/04 22:13:47 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push_elem(int *arr, int *brr)
{
	int i;

	if (brr[0] == 0)
		return ;
	i = arr[0];
	while (i > 0)
	{
		arr[i + 1] = arr[i];
		--i;
	}
	arr[1] = brr[1];
	i = 1;
	while (i < brr[0])
	{
		brr[i] = brr[i + 1];
		++i;
	}
	brr[brr[0]] = MINT;
	++arr[0];
	--brr[0];
}
