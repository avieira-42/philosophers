#include <unistd.h>
#include "../include/philo.h"

void	*death_collector(void *arg)
{
	t_feast	*feast;

	(void)feast;
	feast = (t_feast *)arg;
	wait_all(&feast->philos[0]);
	return (NULL);
}
