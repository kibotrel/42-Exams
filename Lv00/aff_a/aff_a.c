/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 11:26:12 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/26 11:26:13 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	while(ac >= 1)
	{
		if (ac != 2 || *av[1]++ == 'a')
			return (0 * write(1, "a\n", 2));
		if (*av[1] == '\0')
			return (0 * write(1, "\n", 1));
	}
}
