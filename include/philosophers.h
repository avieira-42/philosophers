#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include <stdarg.h>
# include <fcntl.h>
# include <sys/time.h>
# include <pthread.h>

// PHILOSOPHER STRUCT
typedef struct s_philosopher
{
}	t_philosopher;

// SIMULATION STRUCT
typedef struct s_simulation
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	int				*fork;
	int				*chair;
	pthread_t		*philosopher;
	pthread_t		feast;
	pthread_mutex_t	begin;
	pthread_mutex_t	fork_handling;
	//pthread_mutex_t	philosopher_number_generator;
}	t_simulation;

// PARSE MESSAGES
# define MSG_USE "Use: ./prog <philoNo> <dieTime> <sleepTime> <eatTimeNo>(op)\n"
# define MSG_ALLOC_ERR "Couldn't allocate memory\n"

// STATE MESSAGES

/* A displayed state message should not overlap with another message
 * A message announcing a philosopher's death must be displayed
 * within 10 ms of their actual death */

# define MSG_TAKEN_FORK "%i has taken a fork\n"
# define MSG_EATING "%i is eating\n"
# define MSG_SLEEPING "%i is sleeping\n"
# define MSG_THINKING "%i is thinking\n"
# define MSG_DIED "%i died\n"


void    error_exit(int error_code, void *memory, void *memory2);

void    parse_arguments(int argc, char **argv);

void	ft_putstr_fd(char *s, int fd);

int		ft_atoi(const char *nptr);

#endif
