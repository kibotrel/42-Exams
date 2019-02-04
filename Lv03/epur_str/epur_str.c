/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 03:36:26 by kibotrel          #+#    #+#             */
/*   Updated: 2019/01/25 04:00:06 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	epur_str(char *str)
{
	if (*str)
	{
		while (*str && (*str == ' ' || *str == '\t'))
			str++;
		while (*str && *str != ' ' && *str != '\t')
		{
			write(1, &*str, 1);
			str++;
		}
		while (*str)
		{
			while (*str && (*str == ' ' || *str == '\t'))
				str++;
			if (*str)
				write(1, " ", 1);
			while (*str && *str != ' ' && *str != '\t')
			{
				write(1, &*str, 1);
				str++;
			}
		}
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		epur_str(av[1]);
	write(1, "\n", 1);
	return (0);
}
