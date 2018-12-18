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
	int i;
	int j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (s1[i] && s2[j])
	{
		if (s1[i] == s2[j])
		{
			i++;
			j++;
			count++;
		}
		else
			j++;
	}
	return ((count == ft_strlen(s1) ? 1 : 0));
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		if (wdmatch(av[1], av[2]))
				write (1, av[1], ft_strlen(av[1]));
	}
	write (1, "\n", 1);
	return (0);
}
