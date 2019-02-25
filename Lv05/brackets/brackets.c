/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 22:53:52 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/23 10:52:03 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#define BUFF_SIZE 4096

int     match(char a, char b)
{
    return ((a == ')' && b == '(')
        || (a == ']' && b == '[')
        || (a == '}' && b == '{'))
}

int     brackets(char *s)
{
    char    tmp[BUFF_SIZE];
    int     i;

    i = 0;
    tmp[0] = 0;
    while (*s)
    {
        if (*s == '(' || *s == '{' || *s == '[')
            tmp[i++] = *s;
        if (*s == ')' || *s == '}' || *s == ']')
            if (!match(*s, tmp[--i]))
                return (0);
        s++;
    }
    return (i == 0 ? 1 : 0);
}

int     main(int ac, char **av)
{
    int i;

    i = 1;
    if (ac >= 2)
    {
        while (i < ac)
        {
            if (brackets(av[i++]))
                write(1, "OK\n", 3);
            else
                write(1, "Error\n", 6);
        }
    }
    else
        write(1, "\n", 1);
    return (0);
}
