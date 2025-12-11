#include <unistd.h>
#include "../include/philo.h"

static inline
	bool	philo_died(t_philo *philo)
{
	long	elapsed;
	long	t_to_die;

	elapsed = time_get() - get_long(&philo->mutex, &philo->last_meal);
	t_to_die = philo->feast->rules.time_to_die;

	if (elapsed >= t_to_die)
		return (true);
	return (false);
}

void	*death_collector(void *arg)
{
	int		i;
	t_feast	*feast;

	feast = (t_feast *)arg;
	all_sat(&feast->mutex, &feast->threads_run_n, feast->rules.ph_n);
	while (!feast_ended(&feast->death, &feast->end))
	{
		i = 0;
		while (i < feast->rules.ph_n)
		{
			if (philo_died(&feast->philos[i]))
			{
				set_bool(&feast->death, &feast->end, true);
				state_write(DIED, feast, i);
				return (NULL);
			}
			i++;
		}
		usleep(500);
	}
	return (NULL);
}
