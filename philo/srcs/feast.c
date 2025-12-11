#include <unistd.h>
#include "../include/philo.h"

static inline
	int	feast_celebrate(t_feast *feast, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		write(1, "here\n", 5);
		pthread_join(feast->philos[i].thread, NULL);
		i++;
	}
	return (0);
}

int	feast_begin(t_feast *feast)
{
	int			i;

	i = 0;
	while (i < feast->rules.ph_n)
	{
		if (i == 1)
			return (feast_celebrate(feast, i));
		else if (pthread_create(&feast->philos[i].thread,
					NULL, philo_live, &feast->philos[i]) == -1)
			return (feast_celebrate(feast, i));
		i++;
	}
	if (pthread_create(&feast->death_collector,
					NULL, death_collector, feast))
			return (feast_celebrate(feast, feast->rules.ph_n - 1));
	feast->rules.start = time_get();
	set_bool(&feast->wait, &feast->rules.wait, false);
	feast_celebrate(feast, feast->rules.ph_n);
	set_bool(&feast->mutex, &feast->end, true);
	pthread_join(feast->death_collector, NULL);
	return (0);
}
