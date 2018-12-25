#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	prompt_content(unsigned char c)
{
	if (c > 31 && c < 127)
		ft_putchar(c);
	else
		ft_putchar('.');
}

void	prompt_hex(unsigned char hex)
{
	char		*base;

	base = "0123456789abcdef";
	write(1, &base[hex / 16], 1);
	write(1, &base[hex % 16], 1);
	
}

void	translate_hex(unsigned char *string, size_t current_line, size_t size)
{
	size_t		i;

	i = 0;
	while (i < 16)
	{
		if (i && i % 2 == 0)
			ft_putchar(' ');
		if (current_line * 16 + i < size)
			prompt_hex(string[i]);
		else
			write(1, "  ", 2);
		i++;
	}	

}

void	ft_print_memory(const void *addr, size_t size)
{
	size_t		current_line;
	size_t		i;
	unsigned char	*string;

	current_line = 0;
	string = (unsigned char*)addr;
	while (current_line * 16 < size)
	{
		translate_hex(string, current_line, size);
		ft_putchar(' ');
		i = 0;
		while (i < 16)
		{
			if (current_line * 16 + i < size)
				prompt_content(string[i]);
			i++;
		}
		ft_putchar('\n');
		string += 16;
		current_line++;
	}
}

int	main(void)
{
	char *str = "ceci est un test qualitatif";

	ft_print_memory(str, 24);
	return (0);
}
