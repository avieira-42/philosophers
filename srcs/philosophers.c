#include <stdbool.h>
#include "../include/philosophers.h"

void	*philosopher_simulate(void *simulation);

void	simulation_init(t_simulation *simulation, int argc, char **argv)
{
	size_t	i;

	simulation->number_of_philosophers = ft_atoi(argv[1]);
	simulation->time_to_die = ft_atoi(argv[2]);
	simulation->time_to_eat = ft_atoi(argv[3]);
	simulation->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 5)
		simulation->number_of_times_each_philosopher_must_eat = 0;
	else if (argc == 6)
		simulation->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	simulation->fork = malloc(sizeof(int) * simulation->number_of_philosophers);
	if (simulation->fork == NULL)
		error_exit(2, NULL, NULL);
	i = 0;
	simulation->chair = malloc(sizeof(int) * simulation->number_of_philosophers);
	if (simulation->chair == NULL)
		error_exit(2, simulation->fork, NULL);
	while (i < simulation->number_of_philosophers)
	{
		simulation->fork[i] = 0;
		simulation->chair[i] = 0;
		i++;
	}
	simulation->philosopher = malloc(sizeof(pthread_t) * ft_atoi(argv[1]));
	if (simulation->philosopher == NULL)
		error_exit(2, simulation->fork, simulation->chair);
	pthread_mutex_init(&simulation->begin, NULL);
	pthread_mutex_init(&simulation->fork_handling, NULL);
	//pthread_mutex_init(&simulation->philosopher_number_generator, NULL);
}

void	simulation_begin(t_simulation *simulation)
{
	size_t	i;

	i = 0;
	pthread_mutex_lock(&simulation->begin);
	while (i < simulation->number_of_philosophers)
	{
		pthread_create(&simulation->philosopher[i],
				NULL, philosopher_simulate, simulation);
		i++;
	}
	pthread_mutex_unlock(&simulation->begin);
	i = 0;
	while (i < simulation->number_of_philosophers)
	{
		pthread_join(simulation->philosopher[i], NULL);
		i++;
	}
	pthread_mutex_destroy(&simulation->begin);
	pthread_mutex_destroy(&simulation->fork_handling);
	//pthread_mutex_destroy(&simulation->philosopher_number_generator);
}

void
	philosopher_number_assign(t_simulation *simulation, int *philosopher_number)
{
	size_t	i;

	i = 0;
	while (i < simulation->number_of_philosophers)
	{
		if (simulation->chair[i] == 0)
			break;
		i++;
	}
	simulation->chair[i] = -1;
	*philosopher_number = i + 1;
}

bool	fork_pick_up(t_simulation *simulation, int philosopher_number)
{
	if (philosopher_number == 1)
	{
		if (simulation->fork[1] == 0
			&& simulation->fork[simulation->number_of_philosophers] == 0)
		{
			simulation->fork[1] = -1;
			printf(MSG_TAKEN_FORK, philosopher_number);
			simulation->fork[simulation->number_of_philosophers] = -1;
			printf(MSG_TAKEN_FORK, philosopher_number);
			return (true);
		}
	}
	else
	{
		if (simulation->fork[philosopher_number] == 0
			&& simulation->fork[philosopher_number - 1] == 0)
		{
			simulation->fork[philosopher_number] = -1;
			printf(MSG_TAKEN_FORK, philosopher_number);
			simulation->fork[philosopher_number - 1] = -1;
			printf(MSG_TAKEN_FORK, philosopher_number);
			return (true);
		}
	}
	return (false);
}

void	fork_put_down(t_simulation *simulation, int philosopher_number)
{
	simulation->fork[philosopher_number] = 0;
	if (philosopher_number == 1)
		simulation->fork[simulation->number_of_philosophers] = 0;
	else
		simulation->fork[philosopher_number - 1] = 0;
}

void	*philosopher_simulate(void *arg)
{
	bool			can_eat;
	int				philosopher_number;
	t_simulation	*simulation;

	can_eat = false;
	simulation = (t_simulation *) arg;
	pthread_mutex_lock(&simulation->begin);
	philosopher_number_assign(simulation, &philosopher_number);
	//printf("I am philosopher %i\n", philosopher_number);
	pthread_mutex_unlock(&simulation->begin);
	while (1)
	{
		while (can_eat == false)
		{
			pthread_mutex_lock(&simulation->fork_handling);
			can_eat = fork_pick_up(simulation, philosopher_number);
			pthread_mutex_unlock(&simulation->fork_handling);
		}
		printf(MSG_EATING, philosopher_number);
		usleep(simulation->time_to_eat);
		pthread_mutex_lock(&simulation->fork_handling);
		fork_put_down(simulation, philosopher_number);
		printf(MSG_SLEEPING, philosopher_number);
		pthread_mutex_unlock(&simulation->fork_handling);
		can_eat = false;
		usleep(simulation->time_to_sleep);
	}
	return (NULL);
}

int main(int argc, char **argv)
{
	t_simulation	simulation;

	parse_arguments(argc, argv);
	simulation_init(&simulation, argc, argv);
	simulation_begin(&simulation);
}
