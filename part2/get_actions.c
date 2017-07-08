/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 22:44:03 by twalton           #+#    #+#             */
/*   Updated: 2017/07/05 22:44:03 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	free_the_strings(char **strarr, int fail_index)
{
	int i;

	i = 0;
	while (i < fail_index)
	{
		free(strarr[i]);
		++i;
	}
	free(strarr);
}

static char	*translate_ops(int op_num)
{
	if (op_num == 1)
		return (ft_strdup("pb"));
	if (op_num == 2)
                return (ft_strdup("sa"));
	if (op_num == 3)
                return (ft_strdup("sb"));
	if (op_num == 4)
                return (ft_strdup("ra"));
	if (op_num == 5)
                return (ft_strdup("rra"));
	if (op_num == 6)
                return (ft_strdup("rb"));
	if (op_num == 7)
                return (ft_strdup("rrb"));
	if (op_num == 8)
                return (ft_strdup("pa"));
	if (op_num == 9)
                return (ft_strdup(""));
}

char	**get_actions(int *arr)
{
	int *op_arr;
	char **strarr;
	int i[2];

	i[0] = 0;
	i[1] = 0;
	if (!(op_arr = sort_arr(arr)))
		return (NULL);
	strarr = malloc(sizeof(char*) * (op_arr[0] - 2));
	while (i[1] < op_arr[0])
	{
		while (op_arr[i[1] == -1)
			++i[1];
		if (!(strarr[i[0]] = translate_ops(op_arr[i[1] + 1])))
		{
			free_the_strings(strarr, i[0]);
			return (NULL);
		}
		++i[0];
		++i[1];
	}
	strarr[i[0]] == NULL;
	return (strarr);
}
