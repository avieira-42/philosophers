#include <unistd.h>
#include "../include/philo.h"

int	parse(int argc, char **argv)
{

	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_is_digit(argv[i][j]) == -1)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
