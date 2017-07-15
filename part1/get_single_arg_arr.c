/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_single_arg_arr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 21:03:51 by twalton           #+#    #+#             */
/*   Updated: 2017/07/14 21:03:51 by twalton          ###   ########.fr       */
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

int			*get_single_arg_arr(char *str)
{
	char	**strarr;
	int		i;
	int		*arr;

	if (!(strarr = ft_strsplit(str, ' ')))
		return (NULL);
	i = 0;
	while (strarr[i])
		++i;
	if (!(arr = malloc(sizeof(int) * (i + 1))))
		return (NULL);
	i = 0;
	while (strarr[i])
	{
		if ((arr[0] = is_valid_arg(strarr[i])) <= 0)
			return (arr);
		arr[i] = ft_atoi(strarr[i]);
		++i;
	}
	arr[0] = i;
	check_for_duplicates(arr);
	return (arr);
}
