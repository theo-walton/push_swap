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

static int	is_valid_arg(char *arg)
{
	int i;

	i = 0;
	if (arg[0] == '-' || arg[0] == '+' || ft_isnum(arg[0]))
		++i;
	else
		return (0);
	while (arg[i])
	{
		if (!ft_isnum(arg[i]))
			return (0);
		++i;
	}
	if (i == 1 && (arg[0] == '-' || arg[0] == '+'))
		return (0);
	if (arg[0] == '-' && ft_atoi(arg) == 0)
		return (0);
	if (arg[0] != '-' && ft_atoi(arg) == -1)
		return (0);
	return (1);
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
		if (!is_valid_arg(av[i]))
		{
			arr[0] = -1;
			return (arr);
		}
		arr[i] = ft_atoi(av[i]);
		++i;
	}
	arr[0] = ac - 1;
	return (arr);
}
