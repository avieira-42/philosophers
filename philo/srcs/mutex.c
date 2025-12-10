#include "../include/philo.h"

void	mutex_handle(t_mutex *mutex, t_option option)
{
	if (option == LOCK)
		pthread_mutex_lock(mutex);
	else if (option == UNLOCK)
		pthread_mutex_unlock(mutex);
}
