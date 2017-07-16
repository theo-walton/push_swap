/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 22:36:29 by twalton           #+#    #+#             */
/*   Updated: 2017/07/14 22:36:29 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	check_str(char *str)
{
	int i;

	i = -1;
	if (ft_strlen(str) > 2)
		return (0);
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	if (ft_atoi(str) == 0)
		return (0);
	return (1);
}

static int	*new_array_of_size(int size)
{
	int *arr;
	int i;

	i = 0;
	if (!(arr = malloc(sizeof(int) * size + 1)))
		return (NULL);
	while (++i <= size)
		arr[i] = i;
	arr[0] = size;
	return (arr);
}

static void	print_arr(int *arr)
{
	int i;

	i = 1;
	write(1, "[ ", 2);
	while (i <= arr[0])
	{
		ft_putnbr(arr[i]);
		if (arr[i] < 10)
			write(1, " ", 1);
		if (i % 10 == 0 && i != arr[0])
			write(1, "\n  ", 3);
		else
			write(1, "  ", 2);
		++i;
	}
	write(1, "\b\b ]\n", 5);
}

int			manage_reverse(char **av)
{
	int size;
	int *arr;

	if (!check_str(av[2]))
	{
		write(1, "Size argument was invalid\n", 26);
		return (0);
	}
	size = ft_atoi(av[2]);
	if (!(arr = new_array_of_size(size)))
	{
		write(1, "Memory Allocation Failed\n", 25);
		return (0);
	}
	if (perform_actions_on_array(check_valid(read_input()), arr))
		print_arr(arr);
	free(arr);
	return (1);
}
