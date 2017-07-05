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

char	*check_valid(char **strarr)
{
	int i;

	i = 0;
	while (is_line(strarr[i]) != 0 && is_line(strarr[i]) != -1)
		i++;
	if (is_line(strarr[i]) == 0)
		return (strarr);
	write(2, "Error", 5);
	return (NULL);
}
