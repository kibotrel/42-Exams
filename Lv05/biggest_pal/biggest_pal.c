#include <unistd.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		is_pal(char *str, int start, int end)
{
	while (start < end)
		if (str[start++] != str[end--])
			return (0);
	return (1);
}

void	tmp_pal(char *str, char tmp[2048], int start, int end)
{
	int	i;

	i = -1;
	while (++i < 2048)
		tmp[i] = 0;
	i = 0;
	while (start <= end)
		tmp[i++] = str[start++];
}
void	biggest_pal(char *str)
{
	int	biggest;
	int	start;
	int	end;
	int	size;
	char tmp[2048];

	start = -1;
	biggest = ft_strlen(str);
	while (str && str[++start])
	{
		end = 0 + start;
		while (end <= biggest)
		{
			if (is_pal(str, start, end) && (end - start + 1) >= size)
			{
				size = end - start + 1;
				tmp_pal(str, tmp, start, end);
			}
			end++;
		}
	}
	write(1, tmp, ft_strlen(tmp));
}

int		main(int ac, char **av)
{
	if (ac == 2)
		biggest_pal(av[1]);
	write(1, "\n", 1);
	return (0);
}
