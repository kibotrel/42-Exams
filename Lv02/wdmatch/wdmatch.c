#include <unistd.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	wdmatch(char *s1, char *s2)
{
	int length;
	int	count;

	length = ft_strlen(s1);
	count = 0;
	while (*s1 && *s2)
	{
		if (*s1 == *s2++)
		{
			s1++;
			count++;
		}
	}
	return ((count == length ? 1 : 0));
}

int	main(int ac, char **av)
{
	if (ac == 3)
		if (wdmatch(av[1], av[2]))
				write(1, av[1], ft_strlen(av[1]));
	write(1, "\n", 1);
	return (0);
}
