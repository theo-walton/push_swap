/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 16:25:25 by twalton           #+#    #+#             */
/*   Updated: 2017/07/15 16:25:25 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdlib.h>
#include "libft.h"
#include <unistd.h>

static int	has_been_taken(int x, int *taken)
{
	int i;

	i = 1;
	while (i <= taken[0])
	{
		if (taken[i] == x)
			return (1);
		i++;
	}
	return (0);
}

static void	print_arr(int *arr, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putnbr(arr[i]);
		write(1, " ", 1);
		i++;
	}
}

static void	print_random(int size)
{
	int i;
	int arr[size];
	int taken[size + 1];

	srand(time(NULL));
	i = 0;
	taken[0] = 0;
	while (i < size)
	{
		arr[i] = rand() % size;
		if (!has_been_taken(arr[i], taken))
		{
			taken[i + 1] = arr[i];
			taken[0]++;
			i++;
		}
	}
	print_arr(arr, size);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	print_random(ft_atoi(av[1]));
}
