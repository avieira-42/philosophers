#include <unistd.h>
#include "../include/philo.h"

static inline
	void	ft_usleep(long long time)
{
	(void)time;
}

static inline
	void	*death_collector(void *arg)
{
	t_feast	*feast;

	(void)feast;
	feast = (t_feast *)arg;
	return (NULL);
}

static
	void *philo_live(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->bloated)
	{
		state_write(time_get() - philo->start, philo->id, MSG_EATING);
		usleep(philo->rules.time_to_eat * 1000);
		state_write(time_get() - philo->start, philo->id, MSG_SLEEPING);
		usleep(philo->rules.time_to_sleep * 1000);
		state_write(time_get() - philo->start, philo->id, MSG_THINKING);
	}
	return (NULL);
}

static
	void	feast_celebrate(t_feast *feast)
{
	int	i;

	i = 0;
	while (i < feast->rules.ph_n)
	{
		pthread_join(feast->philos[i].thread, NULL);
		i++;
	}
}

static
	int	feast_begin(t_feast *feast)
{
	int			i;
	long long	start;

	i = 0;
	start = time_get();
	while (i < feast->rules.ph_n)
	{
		feast->philos[i].last_meal = start;
		feast->philos[i].start = start;
		if (pthread_create(&feast->philos[i].thread,
					NULL, philo_live, &feast->philos[i]) == -1)
			return (-1);
		i++;
	}
	if (pthread_create(&feast->death_collector,
					NULL, death_collector, feast))
			return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_feast	feast;

	if (argc != 5 && argc != 6)
	{
		write(1, MSG_USAGE, ft_strlen(MSG_USAGE));
		return (1);
	}
	if (parse(argc, argv) == -1)
	{
		write(1, MSG_USAGE_2, ft_strlen(MSG_USAGE_2));
		return (2);
	}
	if (feast_init(&feast, argc, argv) == -1)
		return (3);
	feast_begin(&feast);
	feast_celebrate(&feast);
}
