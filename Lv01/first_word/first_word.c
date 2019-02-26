/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 11:21:51 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/26 11:21:52 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_isspace(char c)
{
	return ((c == ' ' || c == '\t') ? 1 : 0);
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		while (av[1] && ft_isspace(av[1][i]))
			i++;
		while (av[1][i] != '\0' && !ft_isspace(av[1][i]))
			write(1, &av[1][i++], 1);
	}
	write(1, "\n", 1);
	return (0);
}
