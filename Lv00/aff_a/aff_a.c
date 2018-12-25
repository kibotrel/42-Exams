#include <unistd.h>

int	main(int ac, char **av)
{
	while(ac >= 1)
	{
		if (ac != 2 || *av[1]++ == 'a')
			return (0 * write(1, "a\n", 2));
		if (*av[1] == '\0')
			return (0 * write(1, "\n", 1));
	}
}
