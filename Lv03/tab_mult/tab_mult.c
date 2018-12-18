#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int		small_atoi(char *str)
{
	int	result;
	int i;

	result = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + ((int)(str[i++] - '0'));
	return (result);
}

void	small_putnbr(int n)
{
	if (n > 9)
	{
		small_putnbr(n / 10);
		small_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');

}

void	tab_mult(int base)
{
	int	mult;

	mult = 0;
	if (base > 238609294)
		return ;
	while (++mult <= 9)
	{
		small_putnbr(mult);
		write(1, " x ", 3);
		small_putnbr(base);
		write(1, " = ", 3);
		small_putnbr(base * mult);
		ft_putchar('\n');
	}	
}

int		main(int ac, char **av)
{
	if (ac == 2)
		tab_mult(small_atoi(av[1]));
	else
		ft_putchar('\n');
	return (0);
}
