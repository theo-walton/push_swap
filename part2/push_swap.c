/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 21:59:04 by twalton           #+#    #+#             */
/*   Updated: 2017/07/05 21:59:04 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int ac, char **av)
{
	int *arr;
	char **strarr;

	arr = get_array(ac, av);
	strarr = get_actions(arr);
	free(arr);
	put_actions(strarr);
	free_strarr(strarr);
}
