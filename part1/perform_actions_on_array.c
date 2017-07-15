/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_actions_on_array.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 23:08:30 by twalton           #+#    #+#             */
/*   Updated: 2017/07/14 23:08:30 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	perform_action2(char *action, int *brr, int *arr)
{
	if (!ft_strcmp(action, "rb"))
		rot_elem(brr, '+');
	else if (!ft_strcmp(action, "rr"))
	{
		rot_elem(arr, '+');
		rot_elem(brr, '+');
	}
	else if (!ft_strcmp(action, "rra"))
		rot_elem(arr, '-');
	else if (!ft_strcmp(action, "rrb"))
		rot_elem(brr, '-');
	else if (!ft_strcmp(action, "rrr"))
	{
		rot_elem(arr, '-');
		rot_elem(brr, '-');
	}
}

static void	perform_action(char *action, int *brr, int *arr)
{
	if (!ft_strcmp(action, "sa"))
		swap_elem(arr);
	else if (!ft_strcmp(action, "sb"))
		swap_elem(brr);
	else if (!ft_strcmp(action, "ss"))
	{
		swap_elem(arr);
		swap_elem(brr);
	}
	else if (!ft_strcmp(action, "pa"))
		push_elem(arr, brr);
	else if (!ft_strcmp(action, "pb"))
		push_elem(brr, arr);
	else if (!ft_strcmp(action, "ra"))
		rot_elem(arr, '+');
	else
		perform_action2(action, brr, arr);
}

static void	strarr_free(char **strarr)
{
	int i;

	i = 0;
	while (strarr[i])
		free(strarr[i++]);
	free(strarr);
}

int			perform_actions_on_array(char **strarr, int *arr)
{
	int brr[arr[0] + 1];
	int i;

	if (strarr == NULL)
		return (0);
	i = 0;
	brr[0] = 0;
	while (strarr[i])
		perform_action(strarr[i++], brr, arr);
	strarr_free(strarr);
	if (brr[0] != 0)
	{
		write(1, "Not all elements are in A\n", 26);
		return (0);
	}
	return (1);
}
