/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moment.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 16:21:28 by kibotrel          #+#    #+#             */
/*   Updated: 2019/01/10 12:45:43 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#define SECOND 1
#define MINUTE 60
#define HOUR 3600
#define DAY 86400
#define MONTH 2592000

int				ft_strlen(char *str)
{
	int				i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char			*small_itoa(unsigned int nb)
{
	char			*value;
	int				length;
	unsigned int	remaining;

	remaining = nb;
	length = 1;
	while (nb / 10 && length++)
		nb /= 10;
	if (!(value = (char*)malloc(sizeof(*value) * (length + 1))))
		return (NULL);
	value[length] = '\0';
	value[0] = '0';
	while (--length >= 0)
	{
		value[length] = (char)((remaining % 10) + '0');
		remaining /= 10;
	}
	return (value);
}

char			*ft_strjoin(char *s1, char *s2)
{

	int				i;
	char			*time;

	i = 0;
	if (!(time = (char*)malloc(sizeof(*time) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (*s1)
		time[i++] = *s1++;
	while (*s2)
		time[i++] = *s2++;;
	time[i] = '\0';
	return (time);
}

char			*moment(unsigned int duration)
{
	char			*time;
	char			*value;

	if (duration >= MONTH)
		return (time = ((duration / MONTH) <= 1 ? "1 month ago." : ft_strjoin(small_itoa(duration / MONTH), " months ago.")));
	else if (duration >= DAY)
		return (time = ((duration / DAY) <= 1 ? "1 day ago." : ft_strjoin(small_itoa(duration / DAY), " days ago.")));
	else if (duration >= HOUR)
		return (time = ((duration / HOUR) <= 1 ? "1 hour ago." : ft_strjoin(small_itoa(duration / HOUR), " hours ago.")));
	else if (duration >= MINUTE)
		return (time = ((duration / MINUTE) <= 1 ? "1 minute ago." : ft_strjoin(small_itoa(duration / MINUTE), " mintutes ago.")));
	else if (duration >= SECOND)
		return (time = ((duration / SECOND) <= 1 ? "1 second ago." : ft_strjoin(small_itoa(duration / SECOND), " seconds ago.")));
	return (time = "0 seconds ago.");
}
