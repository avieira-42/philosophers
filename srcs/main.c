#include <stdbool.h>
#include <sys/time.h>
#include "../include/philo.h"

void	*philo_routine(void *arg);
void	*death_collector(void *arg);

long long	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((long long) (tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

long long	get_current_time_stamp(long long feast_start)
{
	return (get_current_time() - feast_start);
}

void	rules_init(t_rule *rule, int argc, char **argv)
{
	rule->number_of_philosophers = ft_atol(argv[1]);
	rule->time_to_die = ft_atol(argv[2]);
	rule->time_to_eat = ft_atol(argv[3]);
	rule->time_to_sleep = ft_atol(argv[4]);
	if (argc == 5)
		rule->times_each_philosopher_must_eat = 0;
	else if (argc == 6)
		rule->times_each_philosopher_must_eat = ft_atol(argv[5]);
}

void	philo_init(t_feast *feast, t_philo **philo, size_t philo_total)
{
	size_t	i;
	
	*philo = malloc(sizeof(t_philo) * philo_total);
	if (*philo == NULL)
		error_exit(feast, 2);
	i = 0;
	while (i < philo_total)
	{
		(*philo)[i].philo_total = philo_total;
		(*philo)[i].life_return = -1;
		(*philo)[i].last_meal_mutex_return = -1;
		(*philo)[i].chair = 0;
		(*philo)[i].last_meal = 0;
		(*philo)[i].mutex = NULL;
		(*philo)[i].rule = feast->rule;
		i++;
	}
}

void	meals_preparation(t_feast *feast, t_mutex **mutex)
{
	int	i;

	(*mutex)->fork = malloc(
			sizeof(pthread_mutex_t) * (feast->rule.number_of_philosophers + 1));
	if ((*mutex)->fork == NULL)
		error_exit(feast, 2);
	(*mutex)->fork_return = malloc(
			sizeof(int) * (feast->rule.number_of_philosophers + 1));
	if ((*mutex)->fork_return == NULL)
		error_exit(feast, 2);
	i = 0;
	while (i <= feast->rule.number_of_philosophers)
	{
		(*mutex)->fork_return[i] = -1;
		i++;
	}
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

void	monitor_init(t_feast *feast, t_monitor *monitor)
{
	monitor->camera_return = -1;
	monitor->philo = feast->philo;
	monitor->death = false;
}

void	feast_prepare(t_feast *feast, int argc, char **argv)
{
	feast->philo = NULL;
	feast->mutex = NULL;
	rules_init(&feast->rule, argc, argv);
	philo_init(feast, &feast->philo, feast->rule.number_of_philosophers);
	monitor_init(feast, &feast->monitor);
	mutexes_init(feast, &feast->mutex);
}

void	feast_welcoming(t_feast *feast, t_philo *philo)
{
	int	i;

	i = 0;
	feast->start = get_current_time();
	pthread_mutex_lock(&feast->mutex->welcoming);
	while (i < feast->rule.number_of_philosophers)
	{
		philo[i].death = &feast->monitor.death;
		philo[i].chair = i + 1;
		convert_names_1(philo[i].chair, &philo[i].name);
		philo[i].mutex = feast->mutex;
		philo[i].start = feast->start;
		philo[i].last_meal_mutex_return = pthread_mutex_init(
				&philo[i].last_meal_mutex, NULL);
		if (philo[i].last_meal_mutex_return == -1)
			error_exit(feast, 2);
		if (pthread_create(&philo[i].life, NULL, philo_routine, &philo[i]) != 0)
			error_exit(feast, 2);
		philo[i].life_return = 0;
		i++;
	}
	pthread_mutex_unlock(&feast->mutex->welcoming);
	feast->monitor.camera_return = pthread_create(&feast->monitor.camera, NULL,
				death_collector, feast);
	if (feast->monitor.camera_return == -1)
		error_exit(feast, 2);
}

void	feast_celebration(t_feast *feast)
{
	int	i;

	i = 0;
	while (i < feast->rule.number_of_philosophers)
	{
		pthread_join(feast->philo[i].life, NULL);
		i++;
	}
	pthread_join(feast->monitor.camera, NULL);
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

void	*death_collector(void *arg)
{
	t_feast	*feast;
	int		i;

	feast = (t_feast *) arg;
	while (1)
	{
		i = 0;
		while (i < feast->monitor.philo[0].philo_total)
		{
			pthread_mutex_lock(&feast->monitor.philo[i].last_meal_mutex);
			//printf("%llu\n", get_current_time_stamp(monitor->philo[i].start) - monitor->philo[i].last_meal);
			//printf("%llu\n", monitor->philo[i].rule.time_to_die);
			if (get_current_time_stamp(
						feast->monitor.philo[i].start) - feast->monitor.philo[i].last_meal
						>= feast->monitor.philo[i].rule.time_to_die)
			{
				feast->monitor.death = true;
				pthread_mutex_unlock(&feast->monitor.philo[i].last_meal_mutex);
				printf(MSG_DIED, get_current_time_stamp(
						feast->monitor.philo[i].start),
						feast->monitor.philo[i].chair, feast->monitor.philo[i].name);
				return (NULL);
			}
			pthread_mutex_unlock(&feast->monitor.philo[i].last_meal_mutex);
			i++;
		}
	}
	return (NULL);
}

void	state_message_print(t_philo *philo, char *msg, long long time)
{
	if (*(philo->death) == true)
		return ;
	printf(msg, time,
			philo->chair, philo->name);
}

void	*philo_routine(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *) arg;
	pthread_mutex_lock(&philo->mutex->welcoming);
	pthread_mutex_unlock(&philo->mutex->welcoming);
	while (*(philo->death) == false)
	{
		fork_pick_up(philo);
		pthread_mutex_lock(&philo->last_meal_mutex);
		philo->last_meal = get_current_time_stamp(philo->start);
		state_message_print(philo, MSG_EATING, philo->last_meal);
		pthread_mutex_unlock(&philo->last_meal_mutex);
		usleep(philo->rule.time_to_eat * 1000);
		fork_put_down(philo);
		state_message_print(philo, MSG_SLEEPING,
				get_current_time_stamp(philo->start));
		usleep(philo->rule.time_to_sleep * 1000);
		state_message_print(philo, MSG_THINKING,
				get_current_time_stamp(philo->start));
	}
	return (NULL);
}

int main(int argc, char **argv)
{
	t_feast	feast_contents;

	parse_arguments(argc);
	feast(&feast_contents, argc, argv);
}
