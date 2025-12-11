#include <unistd.h>
#include "../include/philo.h"

static inline
	void	thinking(t_philo *philo)
{
	long	t_eat;
	long	t_sleep;
	long	t_think;


	state_write(THINKING, philo->feast, philo->n - 1);
	if (philo->feast->rules.ph_n % 2 == 0)
		return ;
	t_eat = philo->feast->rules.time_to_eat;
	t_sleep = philo->feast->rules.time_to_sleep;
	t_think = t_eat * 2 - t_sleep;
	if (t_think < 0)
		t_think = 0;
	precise_usleep(t_think * 0.42, philo);
}

static inline
	void	sleeping(t_philo *philo)
{
	state_write(SLEEPING, philo->feast, philo->n - 1);
	precise_usleep(philo->feast->rules.time_to_sleep, philo);
}

static inline
	void	eating(t_philo *philo)
{
	mutex_handle(philo->first_fork, LOCK);
	state_write(TOOK_FIRST_FORK, philo->feast, philo->n - 1);
	mutex_handle(philo->second_fork, LOCK);
	state_write(TOOK_SECOND_FORK, philo->feast, philo->n - 1);
	set_long(&philo->mutex, &philo->last_meal, time_get());
	philo->meals++;
	state_write(EATING, philo->feast, philo->n - 1);
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
	//set_long(&philo->mutex, &philo->last_meal, time_get());
	set_long(&philo->mutex, &philo->last_meal, philo->feast->rules.start);
	increase_long(&philo->feast->mutex, &philo->feast->threads_run_n);
	while (!feast_ended(&philo->feast->death, &philo->feast->end))
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
