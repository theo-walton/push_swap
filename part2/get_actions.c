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

char	**get_actions(int *arr)
{
	int *operation_arr;
	char **strarr;
	int i;

	i = 0;
	if (!(operation_arr = sort_arr(arr)))
		return (NULL);
	strarr = malloc(sizeof(char*) * (operation_arr[0] + 1));
	while (i < operation_arr[0])
	{
		if (!(strarr[i] = translate_ops(operation_arr[i + 1])))
		{
			free_the_strings(strarr, i);
			return (NULL);
		}
		++i;
	}
	strarr[i] == NULL;
	return (strarr);
}
