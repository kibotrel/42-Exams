/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:01:26 by kibotrel          #+#    #+#             */
/*   Updated: 2019/01/10 07:45:27 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		while (*av[1] != '\0')
		{
			if (*av[1] >= 'A' && *av[1] <= 'Z')
				*av[1] = 'A' + (((*av[1] - 'A') + 1) % 26);
			if (*av[1] >= 'a' && *av[1] <= 'z')
				*av[1] = 'a' + (((*av[1] - 'a') + 1) % 26);
			write(1, &*av[1]++, 1);
		}
	}
	write(1,"\n",1);
	return (0);
}
