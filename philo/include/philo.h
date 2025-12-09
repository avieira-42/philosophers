#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

# ifndef PHILO_MAX
#  define PHILO_MAX 200
# endif

typedef pthread_mutex_t t_mutex;
typedef pthread_t t_thread;

# define MSG_USAGE "./philo philo_n time_to_die time_to eat time_to_sleep\
max_meals(optional)"

typedef struct s_philo
{
	int			id;
	long		last_meal;
	t_mutex		*left_fork;
	t_mutex		*right_fork;
	t_thread	thread;

}	t_philo;

typedef struct s_feast
{
	long	philos_n;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	meals_max;
	t_mutex forks[PHILO_MAX];
	t_philo	philos[PHILO_MAX];
}	t_feast;

#endif
