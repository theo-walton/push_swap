/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 20:28:48 by twalton           #+#    #+#             */
/*   Updated: 2017/07/04 20:28:48 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	is_line(char *str)
{
	if (str == NULL)
		return (0);
	if (!ft_strcmp(str, "sa") || !ft_strcmp(str, "sb"))
		return (1);
	if (!ft_strcmp(str, "ss") || !ft_strcmp(str, "pa"))
		return (1);
	if (!ft_strcmp(str, "pb") || !ft_strcmp(str, "ra"))
		return (1);
	if (!ft_strcmp(str, "rb") || !ft_strcmp(str, "rr"))
		return (1);
	if (!ft_strcmp(str, "rra") || !ft_strcmp(str, "rrb"))
		return (1);
	if (!ft_strcmp(str, "rrr"))
		return (1);
	return (-1);
}

static void	free_strarr(char **strarr)
{
	int i;

	i = 0;
	while(strarr[i])
	{
		free(strarr[i]);
		++i;
	}
	free(strarr);
}

char	**check_valid(char **strarr)
{
	int i;

	i = 0;
	if (strarr == NULL)
	{
		write(2, "Memory Allocation Failed\n", 25);
		return (NULL);
	}
	if (strarr == (char**)1)
	{
		write(2, "Nice try... You test pretty well!\n", 34);
		return (NULL);
	}
	while (is_line(strarr[i]) != 0 && is_line(strarr[i]) != -1)
		i++;
	if (is_line(strarr[i]) == 0)
		return (strarr);
	write(2, "Invalid Instruction(s)\n", 23);
	free_strarr(strarr);
	return (NULL);
}
