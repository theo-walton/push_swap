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

	arr = get_array(ac, av);
	if (arr[0] == -1)
		do_stuff();
	if (arr[0] == -2)
		do_other_stuff();
	does_solve(check_valid(read_input()), arr);

}
