/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   does_solve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 20:27:24 by twalton           #+#    #+#             */
/*   Updated: 2017/07/04 20:27:24 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	else if (!ft_strcmp( action, "sb"))
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

static void	check_if_solved(int *brr, int *arr)
{
	int i;

	i = 1;
	if (brr[0])
	{
		write(1, "KO\n", 3);
		return ;
	}
	while (i < arr[0])
	{
		if (arr[i] >= arr[i + 1])
		{
			write(1, "KO\n", 3);
			return ;
		}
		i++;
	}
	write(1, "OK\n", 3);
}

void    does_solve(char **strarr, int *arr)
{
	int brr[arr[0] + 1];
	int i;

	if (strarr == NULL)
		return ;
	i = 0;
	brr[0] = 0;
	while (strarr[i])
		perform_action(strarr[i++], brr, arr);
	check_if_solved(brr, arr);
}
