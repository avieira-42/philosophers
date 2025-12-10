#include "../include/philo.h"

void	wait_all(t_philo *philo)
{
	while (get_bool(&philo->feast->wait, &philo->feast->rules.wait));
}
