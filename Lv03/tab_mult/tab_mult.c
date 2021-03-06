/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 11:17:22 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/26 11:17:43 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define MAX 238609294

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		small_atoi(char *str)
{
	int	result;
	int i;

	result = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + ((int)(str[i++] - '0'));
	return (result);
}

void	small_putnbr(int n)
{
	if (n > 9)
	{
		small_putnbr(n / 10);
		small_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}

void	tab_mult(int base)
{
	int	mult;

	mult = 0;
	if (base <= MAX)
		while (++mult <= 9)
		{
			small_putnbr(mult);
			write(1, " x ", 3);
			small_putnbr(base);
			write(1, " = ", 3);
			small_putnbr(base * mult);
			ft_putchar('\n');
		}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		tab_mult(small_atoi(av[1]));
	else
		ft_putchar('\n');
	return (0);
}
