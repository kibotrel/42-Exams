/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_detector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 10:26:34 by exam              #+#    #+#             */
/*   Updated: 2019/01/15 10:57:58 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int		cycle_detector(const t_list	*list)
{
	const t_list	*cyclehit;

	cyclehit = list;
	list = list->next;
	while (list)
	{
		if (list == cyclehit)
			return (1);
		list = list->next;
	}
	return (0);
}
