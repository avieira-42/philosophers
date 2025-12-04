#ifndef PHILO_H
# define PHILO_H

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

typedef enum s_state
{
	WAITING_TO_EAT,
	EATING,
	SLEEPING,
	THINKING,
}	t_state;

typedef struct s_rule
{
	int			number_of_philosophers;
	int			number_of_times_each_philosopher_must_eat;
	long long	time_to_die;
	long long	time_to_eat;
	long long	time_to_sleep;
}	t_rule;

typedef struct s_mutex
{
	int				queue;
	int				welcoming_return;
	int				fork_handling_return;
	int				fork_handling_state;
	pthread_mutex_t	welcoming;
	pthread_mutex_t	fork_handling;
}	t_mutex;

typedef struct s_philo
{
	int			life_return;
	int			chair;
	int			*fork;
	int			philo_total;
	int			queue_place;
	long long	last_meal;
	t_state		state;
	pthread_t	life;
	t_mutex		*mutex;
	t_rule		rule;
}	t_philo;

typedef struct s_feast
{
	int				*fork;
	int				*chair;
	t_rule			rule;
	t_mutex			*mutex;
	t_philo			*philo;
}	t_feast;

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


void    error_exit(t_feast *feast, int exit_code);

void    parse_arguments(int argc, char **argv);

void	ft_putstr_fd(char *s, int fd);

int		ft_atoi(const char *nptr);

#endif
