#include <unistd.h>
#include "../include/philo.h"

static inline
	void	feast_celebrate(t_feast *feast)
{
	int	i;

	i = 0;
	while (i < feast->rules.ph_n)
	{
		pthread_join(feast->philos[i].thread, NULL);
		i++;
	}
}

int	feast_begin(t_feast *feast)
{
	int			i;

	i = 0;
	while (i < feast->rules.ph_n)
	{
		if (pthread_create(&feast->philos[i].thread,
					NULL, philo_live, &feast->philos[i]) == -1)
			return (-1);
		i++;
	}
	if (pthread_create(&feast->death_collector,
					NULL, death_collector, feast))
			return (-1);
	feast->rules.start = time_get();
	set_bool(&feast->wait, &feast->rules.wait, false);
	feast_celebrate(feast);
	set_bool(&feast->mutex, &feast->end, true);
	pthread_join(feast->death_collector, NULL);
	return (0);
}
