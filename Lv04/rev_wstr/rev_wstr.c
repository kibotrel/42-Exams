#include <unistd.h>

int		count_word(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = -1;

	while (str[++i])
		if (str[i] == ' ' || str[i] == '\t')
			count++;
	return (str[0] != '\0' ? count + 1 : 0);
}
void	rev_wstr(char *str)
{
	int	words;
	int	current;
	int	saved;

	current = 0;	
	words = count_word(str);
	while (str[current])
		current++;
	current--;
	saved = current;
	while (saved >= 0)
	{
		while (current >= 0 && str[current] != ' ' && str[current] != '\t')
			current--;
		saved = current - 1;
		current++;		
		while (str[current] != '\0' && str[current] != ' ' && str[current] != '\t')
			write(1, &str[current++], 1);
		if (words-- > 1)
			write(1, " ", 1);
		current = saved;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		rev_wstr(av[1]);
	write (1, "\n", 1);
	return (0);
}
