#include "../include/philo.h"

bool	all_sat(t_mutex *mutex, long *threads, long philo_n)
{
	bool	ret;

	ret = false;
	mutex_handle(mutex, LOCK);
	if (*threads == philo_n)
		ret = true;
	mutex_handle(mutex, UNLOCK);
	return (ret);
}

void	increase_long(t_mutex *mutex, long *value)
{
	mutex_handle(mutex, LOCK);
	(*value)++;
	mutex_handle(mutex, UNLOCK);
}

void	wait_all(t_philo *philo)
{
	while (get_bool(&philo->feast->wait, &philo->feast->rules.wait));
}
