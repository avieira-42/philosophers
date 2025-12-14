#include "../include/philo.h"

void    error_message_get(int error_code, char **error_message)
{
    *error_message = NULL;
	if (error_code == 1)
        *error_message = MSG_USE;
	else if (error_code == 2)
		*error_message = MSG_ALLOC_ERR;
}

void	philo_farewell(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo[0].philo_total)
	{
		if (philo[i].last_meal_mutex_return == 0)
			pthread_mutex_destroy(&philo[i].last_meal_mutex);
		i++;
	}
	free(philo);
}

void	mutex_destroy(t_mutex *mutex)
{
	if (mutex->fork != NULL)
		free(mutex->fork);
	if (mutex->fork_return != NULL)
		free(mutex->fork_return);
	free(mutex);
}

void	table_clean(t_feast *feast)
{
	if (feast != NULL)
	{
		if (feast->philo != NULL)
			philo_farewell(feast->philo);
		if (feast->mutex != NULL)
			mutex_destroy(feast->mutex);
	}
}

void    error_exit(t_feast *feast, int error_code)
{
	char    *error_message;

	error_message_get(error_code, &error_message);
	ft_putstr_fd(error_message, 2);
	table_clean(feast);
}
