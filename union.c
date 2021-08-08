#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int main(int argc, char** argv)
{
	int i;
	int j;

	if (argc == 3)
	{
		i = 0;
		while (argv[1][i])
		{
			j = 0;
			while (j < i)
			{
				if (argv[1][i] == argv[1][j])
					break;
				j++;
			}
			if (i == j)
				ft_putchar(argv[1][i]);
			i++;
		}
		i = 0;
		while (argv[2][i])
		{	
			j = 0;
			while (argv[1][j])
			{
				if (argv[1][j] == argv[2][i])
					break;
				j++;
			}
			if (argv[1][j] != '\0')
			{
				i++;
				continue;
			}
			j = 0;
			while (j < i)
			{
				if (argv[2][i] == argv[2][j])
					break;
				j++;
			}
			if (i == j)
				ft_putchar(argv[2][i]);
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
