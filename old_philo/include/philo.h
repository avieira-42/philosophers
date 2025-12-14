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
# include <stdbool.h>
# include "../srcs/get_names/get_names.h"

# define MSG_USE "Usage: ./prog <number_of_philosophers> <time_to_die> \
<time_to_eat> <time_to_sleep> <nnumber_of_times_each_philosopher_must_eat> \
(opional)\n"
# define MSG_ALLOC_ERR "Couldn't allocate memory\n"

/* A displayed state message should not overlap with another message
 * A message announcing a philosopher's death must be displayed
 * within 10 ms of their actual death */
# define MSG_TAKEN_FORK "%lld (%i) %s has taken a fork\n"
# define MSG_EATING "%lld (%i) %s is eating pasta\n"
# define MSG_SLEEPING "%lld (%i) %s is taking a well deserved shut eye\n"
# define MSG_THINKING "%lld (%i) %s is frying his brains out\n"
# define MSG_DIED "%lld (%i) %s dead\n"

typedef struct s_rule
{
	int			number_of_philosophers;
	int			times_each_philosopher_must_eat;
	long long	time_to_die;
	long long	time_to_eat;
	long long	time_to_sleep;
}	t_rule;

typedef struct s_mutex
{
	int				*fork_return;
	pthread_mutex_t	*fork;
	int				welcoming_return;
	pthread_mutex_t	welcoming;
}	t_mutex;

typedef struct s_philo
{
	int				life_return;
	int				chair;
	int				philo_total;
	int				last_meal_mutex_return;
	char			*name;
	long long		start;
	long long		*start_ptr;
	long long		last_meal;
	pthread_t		life;
	t_mutex			*mutex;
	pthread_mutex_t	last_meal_mutex;
	t_rule			rule;
	bool			*death;
	pthread_mutex_t *death_mutex;
}	t_philo;

typedef struct s_monitor
{
	int				camera_return;
	int				death_return;
	t_philo			*philo;
	pthread_t		camera;
	bool			death;
	pthread_mutex_t	death_mutex;
}	t_monitor;

typedef struct s_feast
{
	long long		start;
	t_rule			rule;
	t_mutex			*mutex;
	t_philo			*philo;
	t_monitor		monitor;
}	t_feast;

void	error_exit(t_feast *feast, int exit_code);
void	parse_arguments(int argc);
void	ft_putstr_fd(char *s, int fd);
int		ft_atol(const char *nptr);

#endif
