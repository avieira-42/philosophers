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
		(*philo)[i].fork = feast->fork;
		(*philo)[i].last_meal = 0;
		(*philo)[i].state = WAITING_TO_EAT;
		(*philo)[i].mutex = NULL;
		(*philo)[i].rule = feast->rule;
		i++;
	}
}

void	mutexes_init(t_feast *feast, t_mutex **mutex)
{
	*mutex = malloc(sizeof(t_mutex) * 1);
	if (*mutex == NULL)
		error_exit(feast, 2);
	(*mutex)->welcoming_return = -1;
	(*mutex)->fork_handling_return = -1;
	(*mutex)->welcoming_return = pthread_mutex_init(&(*mutex)->welcoming, NULL);
	if ((*mutex)->welcoming_return != 0)
		error_exit(feast, 2);
	(*mutex)->fork_handling_return = pthread_mutex_init(
										&(*mutex)->fork_handling, NULL);
	if ((*mutex)->fork_handling_return != 0)
		error_exit(feast, 2);
}

void	variables_init(t_feast *feast, int philo_total)
{
	size_t	i;

	feast->fork = malloc(sizeof(int) * philo_total);
	if (feast->fork == NULL)
		error_exit(feast, 2);
	feast->chair = malloc(sizeof(int) * philo_total);
	if (feast->chair == NULL)
		error_exit(feast, 2);
	i = 0;
	while (i < feast->rule.number_of_philosophers)
	{
		feast->fork[i] = 0;
		feast->chair[i] = 0;
		i++;
	}
}

void	feast_prepare(t_feast *feast, int argc, char **argv)
{
	feast->fork = NULL;
	feast->chair = NULL;
	feast->philo = NULL;
	rules_init(&feast->rule, argc, argv);
	variables_init(feast, feast->rule.number_of_philosophers);
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
	pthread_mutex_destroy(&feast->mutex->welcoming);
	pthread_mutex_destroy(&feast->mutex->fork_handling);
	// print message ?
}

void	feast(t_feast *feast, int argc, char **argv)
{
	feast_prepare(feast, argc, argv);
	feast_welcoming(feast, feast->philo);
	feast_celebration(feast);
	feast_leave_taking(feast);
}

void	philo_number_assign(t_feast *feast, int *philo_number)
{
	size_t	i;

	i = 0;
	while (i < feast->rule.number_of_philosophers)
	{
		if (feast->chair[i] == 0)
			break;
		i++;
	}
	feast->chair[i] = -1;
	*philo_number = i + 1;
}

bool	fork_pick_up(t_philo *philo)
{
	if (philo->chair == 1)
	{
		if (philo->fork[1] == 0
				&& philo->fork[philo->philo_total] == 0)
		{
			philo->fork[1] = -1;
			printf(MSG_TAKEN_FORK, philo->chair);
			philo->fork[philo->philo_total] = -1;
			printf(MSG_TAKEN_FORK, philo->chair);
			return (true);
		}
	}
	else
	{
		if (philo->fork[philo->chair] == 0
				&& philo->fork[philo->chair - 1] == 0)
		{
			philo->fork[philo->chair] = -1;
			printf(MSG_TAKEN_FORK, philo->chair);
			philo->fork[philo->chair - 1] = -1;
			printf(MSG_TAKEN_FORK, philo->chair);
			return (true);
		}
	}
	return (false);
}

void	fork_put_down(t_philo *philo)
{
	philo->fork[philo->chair] = 0;
	if (philo->chair == 1)
		philo->fork[philo->rule.number_of_philosophers] = 0;
	else
		philo->fork[philo->chair - 1] = 0;
}

void	*philo_routine(void *arg)
{
	bool			can_eat;
	t_philo			*philo;

	can_eat = false;
	philo = (t_philo *) arg;
	pthread_mutex_lock(&philo->mutex->welcoming);
	printf("I am in the chair %i\n", philo->chair);
	pthread_mutex_unlock(&philo->mutex->welcoming);
	while (1)
	{
		while (can_eat == false)
		{
			pthread_mutex_lock(&philo->mutex->fork_handling);
			can_eat = fork_pick_up(philo);
			pthread_mutex_unlock(&philo->mutex->fork_handling);
		}
		printf(MSG_EATING, philo->chair);
		usleep(philo->rule.time_to_eat);
		pthread_mutex_lock(&philo->mutex->fork_handling);
		fork_put_down(philo);
		printf(MSG_SLEEPING, philo->chair);
		pthread_mutex_unlock(&philo->mutex->fork_handling);
		can_eat = false;
		usleep(philo->rule.time_to_sleep);
	}
	return (NULL);
}

int main(int argc, char **argv)
{
	t_feast	feast_contents;

	parse_arguments(argc, argv);
	feast(&feast_contents, argc, argv);
}
