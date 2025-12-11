#include "../include/philo.h"

#include <stdio.h>
int	error_return(t_feast *feast, int error_code)
{
	int	i;

	printf("%i\n", error_code);
	if (error_code-- > 0)
		pthread_mutex_destroy(&feast->mutex);
	if (error_code-- > 0)
		pthread_mutex_destroy(&feast->wait);
	if (error_code-- > 0)
		pthread_mutex_destroy(&feast->message);
	if (error_code-- > 0)
		pthread_mutex_destroy(&feast->death);
	if (error_code > 0)
	{
		i = 0;
		while (i < feast->rules.ph_n && error_code > 0)
		{
			pthread_mutex_destroy(&feast->forks[i]);
			error_code--;
			i++;
		}
	}
	return (1);
}
