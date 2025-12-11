#include <unistd.h>
#include "../include/philo.h"

int	main(int argc, char **argv)
{
	int		return_code;
	t_feast	feast;

	if (argc != 5 && argc != 6)
	{
		write(1, MSG_USAGE, ft_strlen(MSG_USAGE));
		return (1);
	}
	if (parse(argc, argv) == -1)
	{
		write(1, MSG_USAGE_2, ft_strlen(MSG_USAGE_2));
		return (2);
	}
	return_code = feast_init(&feast, argc, argv);
	if (return_code != 0)
		return (error_return(&feast, return_code));
	feast_begin(&feast);
}
