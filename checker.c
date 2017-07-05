/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 03:28:19 by twalton           #+#    #+#             */
/*   Updated: 2017/07/04 03:28:19 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int ac, char **av)
{
	int *arr;

	if (!(arr = get_array(ac, av)))
	{
		write(2, "Memory Allocation Failed\n", 25);
		return (0);
	}
	if (arr[0] == -1)
	{
		free(arr);
		write(2, "Invalid Argument(s)\n", 20);
		return (0);
	}
	if (arr[0] == -2)
	{
		free(arr);
		return (0);
	}
	does_solve(check_valid(read_input()), arr);
	free(arr);
}
