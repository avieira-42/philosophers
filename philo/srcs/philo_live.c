#include <unistd.h>
#include "../include/philo.h"

static inline
	void	eat(t_philo *philo)
{
	mutex_handle(philo->first_fork, LOCK);
	state_write(TOOK_FIRST_FORK, philo->feast, philo->n - 1);
	mutex_handle(philo->second_fork, LOCK);
	state_write(TOOK_SECOND_FORK, philo->feast, philo->n - 1);
	precise_usleep(philo->feast->rules.time_to_eat, philo);
	set_long(&philo->mutex, &philo->last_meal, time_get());
	philo->meals++;
	precise_usleep(philo->feast->rules.time_to_eat, philo);
	if (philo->feast->rules.meals_max > 0
		&& philo->meals == philo->feast->rules.meals_max)
		set_bool(&philo->mutex, &philo->bloated, true);
	mutex_handle(philo->first_fork, UNLOCK);
	mutex_handle(philo->second_fork, UNLOCK);
}

void *philo_live(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	wait_all(philo);
	while (!philo->bloated)
	{
		eat(philo);

		state_write(SLEEPING, philo->feast, philo->n - 1);
		precise_usleep(philo->feast->rules.time_to_sleep, philo);
		state_write(THINKING, philo->feast, philo->n - 1);
	}
	return (NULL);
}
