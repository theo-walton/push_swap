/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 20:30:01 by twalton           #+#    #+#             */
/*   Updated: 2017/07/04 20:30:01 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_newline(char c, char d)
{
	if (d != '\n')
		write(1, "  \n", 3);
	if (c == '\n' && d == '\n')
		write(1, "\033[F", 4);
}

char	**read_input(void)
{
	char buff[2];
	int toggle1;
	int toggle2;

	toggle1 = 0;
	toggle2 = 0;
	buff[0] = '\0';
	buff[1] = '\0';
	ft_createstr('\n', 10);
	while (buff[0] != '\n' || buff[1] != '\n')
	{
		buff[0] = buff[1];
		if (read(0, buff + 1, 1) == 0 && !(buff[1] = '\0'))
			break ;
		if (buff[1] == '\0')
			toggle2 = 1;
		if (!toggle2 && !toggle1 && !(ft_createstr(buff[1], 10)))
			toggle1 = 1;
	}
	check_newline(buff[1], buff[0]);
	if (toggle1)
		return (NULL);
	if (toggle2)
		return ((char**)1);
	return (ft_strsplit(ft_createstr('\0', 10), '\n'));
}
