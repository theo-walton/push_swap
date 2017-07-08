/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 21:17:21 by twalton           #+#    #+#             */
/*   Updated: 2017/07/07 21:17:21 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_sort(int *arr)
{
	int i;

	i = 1;
	while (i < arr[0])
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}
