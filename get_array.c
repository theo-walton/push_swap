/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 23:13:11 by twalton           #+#    #+#             */
/*   Updated: 2017/07/04 23:13:11 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	check_leading_zeros(char *arg)
{
	if (arg[0] == '0' && arg[1])
		return (-7);
	if ((arg[0] == '-' || arg[0] == '+') && arg[1] == '0' && arg[2])
		return (-7);
	if ((arg[0] == '-' || arg[0] == '+') && arg[1] == '0' && !arg[2])
		return (-8);
	return (1);
}

static int	is_valid_arg(char *arg)
{
	int i;

	i = 0;
	if (arg[0] == '-' || arg[0] == '+' || ft_isdigit(arg[0]))
		++i;
	else
		return (-1);
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (-1);
		++i;
	}
	if (i == 1 && (arg[0] == '-' || arg[0] == '+'))
		return (-6);
	if (check_leading_zeros(arg) < 0)
		return (check_leading_zeros(arg));
	if (arg[0] == '-' && ft_atoi(arg) == 0)
		return (-5);
	if (arg[0] != '-' && ft_atoi(arg) == -1)
		return (-4);
	return (1);
}

static void	check_for_duplicates(int *arr)
{
	int i;
	int j;

	i = 1;
	j = 2;
	while (i <= arr[0])
	{
		while (j <= arr[0])
		{
			if (arr[i] == arr[j])
				arr[0] = -3;
			j++;
		}
		i++;
		j = i + 1;
	}
}

int	*get_array(int ac, char **av)
{
	int *arr;
	int i;

	if (!(arr = malloc(sizeof(int) * ac)))
		return (NULL);
	if (ac <= 1)
	{
		arr[0] = -2;
		return (arr);
	}
	i = 1;
	while (i < ac)
	{
		if ((arr[0] = is_valid_arg(av[i])) <= 0)
			return (arr);
		arr[i] = ft_atoi(av[i]);
		++i;
	}
	arr[0] = ac - 1;
	check_for_duplicates(arr);
	return (arr);
}
