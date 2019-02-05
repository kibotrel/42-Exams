/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest_pal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 10:03:52 by exam              #+#    #+#             */
/*   Updated: 2019/02/05 10:52:03 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
int		is_pal(char *s, int start, int end)
{
	while(start < end)
		if (s[start++] != s[end--])
			return (0);
	return (1);
}
void	biggest_pal(char *s)
{
	int		end;
	int		save;
	int		size;
	int		start;

	size = ft_strlen(s) - 1;
	save = 0;
	start = 0;
	while (s[start])
	{
		end = size;
		while (start >= 0)
		{
			if (is_pal(s, start, end))
			{
				while (start <= end)
					write(1, &s[start++], 1);
				return;
			}
			else
			{
				start--;
				end--;
			}
		}
		save++;
		start = save;

	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		biggest_pal(av[1]);
	write(1, "\n", 1);
	return (0);
}
