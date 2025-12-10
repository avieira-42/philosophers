#include "../include/philo.h"

static inline
	void	rules_init(t_feast *feast, int argc, char **argv)
{
	feast->rules.victim = 0;
	feast->rules.ph_n = ft_atol(argv[1]);
	feast->rules.time_to_die = ft_atol(argv[2]);
	feast->rules.time_to_eat = ft_atol(argv[3]);
	feast->rules.time_to_sleep = ft_atol(argv[4]);
	if (argc == 6)
		feast->rules.meals_max = ft_atol(argv[5]);
	else
		feast->rules.meals_max = -1;
}

static inline
	int	mutexes_init(t_feast *feast)
{
	int	i;

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
	void	philos_init(t_feast *feast)
{
	int	i;

	i = 0;
	while (i < feast->rules.ph_n)
	{
		ft_itoa(i + 1, feast->philos[i].id);
		feast->philos[i].last_meal = 0;
		feast->philos[i].bloated = false;
		feast->philos[i].rules = feast->rules;
		feast->philos[i].death = &feast->death;
		feast->philos[i].message = &feast->message;
		feast->philos[i].left_fork = &feast->forks[i + 1];
		feast->philos[i].right_fork = &feast->forks[i + 1 % feast->rules.ph_n];
		i++;
	}
}

int	feast_init(t_feast *feast, int argc, char **argv)
{
	rules_init(feast, argc, argv);
	if (mutexes_init(feast) == -1)
		return (-1);
	philos_init(feast);
	return (1);
}
