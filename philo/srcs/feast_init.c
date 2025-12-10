#include "../include/philo.h"
#include <stdio.h>

static inline
	int	mutexes_init(t_feast *feast)
{
	int	i;

	if (pthread_mutex_init(&feast->mutex, NULL))
		return (-1);
	if (pthread_mutex_init(&feast->wait, NULL))
		return (-1);
	if (pthread_mutex_init(&feast->message, NULL))
		return (-1);
	if (pthread_mutex_init(&feast->death, NULL))
		return (-1);
	i = 0;
	while (i < feast->rules.ph_n)
	{
		if (pthread_mutex_init(&feast->forks[i], NULL))
			return (-1);
		i++;
	}
	return (0);
}

static inline
	void	buff_init(char *buf)
{
	int	i;

	i = 99;
	while (i > - 1)
	{
		buf[i] = 0;
		i--;
	}
}

static inline
	void	forks_assign(t_philo *philo, t_mutex *forks, int i)
{
	int	philo_n;

	philo_n = philo->feast->rules.ph_n;
	if (philo->n % 2 == 0)
	{
		philo->first_fork = &forks[i];
		philo->second_fork = &forks[(i + 1) % philo_n];
	}
	else
	{
		philo->first_fork = &forks[(i + 1) % philo_n];
		philo->second_fork = &forks[i];
	}
}

static inline
	int	philos_init(t_feast *feast)
{
	int	i;

	i = 0;
	while (i < feast->rules.ph_n)
	{
		buff_init(feast->philos[i].id);
		ft_itoa(i + 1, feast->philos[i].id);
		feast->philos[i].n = i + 1;
		feast->philos[i].last_meal = 0;
		feast->philos[i].bloated = false;
		feast->philos[i].feast = feast;
		feast->philos[i].meals = 0;
		forks_assign(&feast->philos[i], feast->forks, i);
		if (pthread_mutex_init(&feast->philos[i].mutex, NULL) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int	feast_init(t_feast *feast, int argc, char **argv)
{
	feast->end = false;
	feast->rules.wait = true;
	feast->rules.victim = 0;
	feast->rules.ph_n = ft_atol(argv[1]);
	feast->rules.time_to_die = ft_atol(argv[2]);
	feast->rules.time_to_eat = ft_atol(argv[3]);
	feast->rules.time_to_sleep = ft_atol(argv[4]);
	feast->threads_run_n = 0;
	if (argc == 6)
		feast->rules.meals_max = ft_atol(argv[5]);
	else
		feast->rules.meals_max = -1;
	if (mutexes_init(feast) == -1)
		return (-1);
	if (philos_init(feast) == -1)
		return (-1);
	return (1);
}
