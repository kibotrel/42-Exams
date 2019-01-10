/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:17:37 by kibotrel          #+#    #+#             */
/*   Updated: 2019/01/10 07:58:16 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

int	max(int *tab, unsigned int len)
{
	int max;
	unsigned i;

	i = 0;
	max = INT_MIN;
	while (i < len)
		if (tab[i++] > max)
			max = tab[i - 1];
	return (len > 0 ? max : 0);
}
