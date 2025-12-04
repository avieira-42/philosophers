#include <stdbool.h>
#include <sys/time.h>
#include "../include/philo.h"

void	*philo_routine(void *arg);

long long	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((long long) (tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	rules_init(t_rule *rule, int argc, char **argv)
{
	rule->number_of_philosophers = ft_atoi(argv[1]);
	rule->time_to_die = ft_atoi(argv[2]);
	rule->time_to_eat = ft_atoi(argv[3]);
	rule->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 5)
		rule->number_of_times_each_philosopher_must_eat = 0;
	else if (argc == 6)
		rule->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
}

void	philo_init(t_feast *feast, t_philo **philo, int philo_total)
{
	size_t	i;
	
	*philo = malloc(sizeof(t_philo) * philo_total);
	if (*philo == NULL)
		error_exit(feast, 2);
	i = 0;
	while (i < philo_total)
	{
		(*philo)[i].philo_total = philo_total;
		(*philo)[i].life_return = 0;
		(*philo)[i].chair = 0;
		(*philo)[i].last_meal = 0;
		(*philo)[i].state = WAITING_TO_EAT;
		(*philo)[i].mutex = NULL;
		(*philo)[i].rule = feast->rule;
		i++;
	}
}

void	meals_preparation(t_feast *feast, t_mutex **mutex)
{
	size_t	i;

	(*mutex)->fork = malloc(
			sizeof(pthread_mutex_t) * (feast->rule.number_of_philosophers + 1));
	if ((*mutex)->fork == NULL)
		error_exit(feast, 2);
	(*mutex)->fork_return = malloc(
			sizeof(int) * (feast->rule.number_of_philosophers + 1));
	if ((*mutex)->fork_return == NULL)
		error_exit(feast, 2);
	i = 0;
	while (i < feast->rule.number_of_philosophers)
	{
		i++;
		(*mutex)->fork_return[i] = pthread_mutex_init(&(*mutex)->fork[i], NULL);
		if ((*mutex)->fork_return[i] != 0)
			error_exit(feast, 2);
	}
}

void	mutexes_init(t_feast *feast, t_mutex **mutex)
{
	(*mutex) = malloc(sizeof(t_mutex) * 1);
	(*mutex)->fork = NULL;
	(*mutex)->fork_return = NULL;
	if (*mutex == NULL)
		error_exit(feast, 2);
	(*mutex)->welcoming_return = -1;
	(*mutex)->welcoming_return = pthread_mutex_init(&(*mutex)->welcoming, NULL);
	if ((*mutex)->welcoming_return != 0)
		error_exit(feast, 2);
	meals_preparation(feast, mutex);
}

void	feast_prepare(t_feast *feast, int argc, char **argv)
{
	feast->philo = NULL;
	feast->mutex = NULL;
	rules_init(&feast->rule, argc, argv);
	philo_init(feast, &feast->philo,
			feast->rule.number_of_philosophers);
	mutexes_init(feast, &feast->mutex);
}

void	feast_welcoming(t_feast *feast, t_philo *philo)
{
	size_t	i;

	i = 0;
	pthread_mutex_lock(&feast->mutex->welcoming);
	while (i < feast->rule.number_of_philosophers)
	{
		philo[i].life_return = 0;
		philo[i].chair = i + 1;
		philo[i].mutex = feast->mutex;
		if (pthread_create(&philo[i].life, NULL, philo_routine, &philo[i]) != 0)
			error_exit(feast, 2);
		i++;
	}
	pthread_mutex_unlock(&feast->mutex->welcoming);
}

void	feast_celebration(t_feast *feast)
{
	size_t	i;

	i = 0;
	while (i < feast->rule.number_of_philosophers)
	{
		pthread_join(feast->philo[i].life, NULL);
		i++;
	}
}

void	feast_leave_taking(t_feast *feast)
{
	error_exit(feast, 0);
}

void	feast(t_feast *feast, int argc, char **argv)
{
	feast_prepare(feast, argc, argv);
	feast_welcoming(feast, feast->philo);
	feast_celebration(feast);
	feast_leave_taking(feast);
}

void	fork_pick_up(t_philo *philo)
{
	if (philo->chair % 2 == 0)
	{
		pthread_mutex_lock(&philo->mutex->fork[philo->chair]);
		pthread_mutex_lock(&philo->mutex->fork[philo->chair - 1]);
	}
	else if (philo->chair == 1)
	{
		pthread_mutex_lock(&philo->mutex->fork[philo->chair]);
		pthread_mutex_lock(&philo->mutex->fork[philo->philo_total]);
	}
	else
	{
		pthread_mutex_lock(&philo->mutex->fork[philo->chair - 1]);
		pthread_mutex_lock(&philo->mutex->fork[philo->chair]);
	}
}

void	fork_put_down(t_philo *philo)
{
	if (philo->chair % 2 == 0)
	{
		pthread_mutex_unlock(&philo->mutex->fork[philo->chair]);
		pthread_mutex_unlock(&philo->mutex->fork[philo->chair - 1]);
	}
	else if (philo->chair == 1)
	{
		pthread_mutex_unlock(&philo->mutex->fork[philo->chair]);
		pthread_mutex_unlock(&philo->mutex->fork[philo->philo_total]);
	}
	else
	{
		pthread_mutex_unlock(&philo->mutex->fork[philo->chair - 1]);
		pthread_mutex_unlock(&philo->mutex->fork[philo->chair]);
	}
}

void	*philo_routine(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *) arg;
	pthread_mutex_lock(&philo->mutex->welcoming);
	printf("I am in the chair %i\n", philo->chair);
	pthread_mutex_unlock(&philo->mutex->welcoming);
	// TRY TO EAT

	return (NULL);
}

int main(int argc, char **argv)
{
	t_feast	feast_contents;

	parse_arguments(argc, argv);
	feast(&feast_contents, argc, argv);
}
