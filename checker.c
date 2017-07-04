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

char	**read_input(void);
{
	while (1)
	{
		get_next_line(0, instruction);
		add_to_instruction_list();
		if (^d is pressed)
			break;
	}
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

void	does_solve(char **strarr, int *arr)
{
	int *brr;
	int i;

	i = 0;
	if (str == NULL)
		return ;
	brr = create_brr(arr);
	while (strarr[i])
		perform_action(strarr[i++], brr, arr);
	check_if_solved(brr, arr);
}

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
