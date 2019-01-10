/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moment.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 16:21:28 by kibotrel          #+#    #+#             */
/*   Updated: 2018/12/14 18:26:01 by kibotrel         ###   ########.fr       */
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

unsigned int	numlen(int nb)
{
	unsigned int	size;

	size = 1;
	while (nb / 10)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

char			*ft_itoa(int nb)
{
	char			*str;
	int				length;
	long			n;

	length = numlen(nb);
	n = nb;
	if (!(str = (char*)malloc(sizeof(*str) * (length + 1))))
		return (NULL);
	str[length--] = '\0';
	str[0] = '0';
	while (n > 0)
	{
		str[length--] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

char			*ft_strcat(char *s1, char *s2)
{

	int				i;
	int				j;

	i = ft_strlen(s1);
	j = -1;
	while (s2[++j])
		s1[i + j] = s2[j];
	s1[i + j] = '\0';
	return (s1);
}

char			*moment(int nb)
{
	char			*number;
	char			*str;
	char			*ret;
	if (nb == 0)
		return (str = "0 seconds ago.");
	else if (nb >= MONTH)
	{
		if (nb / MONTH <= 1)
			return (str = "1 month ago.");
		str = " months ago.";
		number = ft_itoa(nb / MONTH);
		ret = ft_strcat(number, str);
		free(number);
		return (ret);
	}
	else if (nb >= DAY)
	{
		if (nb / DAY <= 1)
			return (str = "1 day ago.");
		str = " days ago.";
		number = ft_itoa(nb / DAY);
		ret = ft_strcat(number, str);
		free(number);
		return (ret);

	}
	else if (nb >= HOUR)
	{
		if (nb / HOUR <= 1)
			return (str = "1 hour ago.");
		str = " hours ago.";
		number = ft_itoa(nb / HOUR);
		ret = ft_strcat(number, str);
		free(number);
		return (ret);
	}
	else if (nb >= MINUTE)
	{
		if (nb / MINUTE <= 1)
			return (str = "1 minute ago.");
		str = " minutes ago.";
		number = ft_itoa(nb / MINUTE);
		ret = ft_strcat(number, str);
		free(number);
		return (ret);
	}
	else if (nb >= SECOND)
	{
		if (nb / SECOND <= 1)
			return (str = "1 second ago.");
		str = " seconds ago.";
		number = ft_itoa(nb / SECOND);
		ret = ft_strcat(number, str);
		free(number);
		return (ret);
	}
	return (NULL);
}
