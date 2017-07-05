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



static void	perform_action(char *action, int *brr, int *arr)
{
	if (!ft_strcmp(action, "sa"))
		swap_elem(arr);
}

void    does_solve(char **strarr, int *arr)
{
	int *brr;
	int i;

	i = 0;
	if (str == NULL)
		return ;
	brr = ft_memalloc(sizeof(int) * arr[0]);
	while (strarr[i])
		perform_action(strarr[i++], brr, arr);
	check_if_solved(brr, arr + 1);
	free(brr);
}
