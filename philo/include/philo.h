#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>

# ifndef PHILO_MAX
#  define PHILO_MAX 200
# endif

typedef pthread_mutex_t t_mutex;
typedef pthread_t t_thread;

# define MSG_USAGE "./philo [philo_n] [time_to_die] [time_to_eat] [time_to_sleep] \
[max_meals](optional)\n"
# define MSG_USAGE_2 "Only positive numbers allowed\n"
# define MSG_FORK "has taken a fork\n"
# define MSG_EATING "is eating\n"
# define MSG_SLEEPING "is_sleeping\n"
# define MSG_THINKING "is_thinking\n"

typedef struct s_rule
{
	int			victim;
	int			meals_max;
	int			ph_n;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
} t_rule;

typedef struct s_philo
{
	char		id[100];
	int			*victim;
	long		last_meal;
	long long	start;
	bool		bloated;
	t_rule		rules;
	t_mutex		*death;
	t_mutex		*message;
	t_mutex		*left_fork;
	t_mutex		*right_fork;
	t_thread	thread;
}	t_philo;

typedef struct s_feast
{
	t_rule		rules;
	t_mutex		message;
	t_mutex		death;
	t_mutex		forks[PHILO_MAX];
	t_philo		philos[PHILO_MAX];
	t_thread	death_collector;
}	t_feast;

/*#######################      UTILS     ###########################*/
void		state_write(long time, char *id, char *state);

/*#######################      PARSE     ###########################*/
int			parse(int argc, char **argv);

/*#######################       LIB      ###########################*/
long		ft_atol(char *nbr);
int			ft_strlen(char *str);
int			ft_is_digit(char c);
void		ft_itoa(int n, char *buf);

/*#######################   FEAST_INIT    ###########################*/
int			feast_init(t_feast *feast, int argc, char **argv);

/*#######################    TIME_GET     ###########################*/
long long	time_get(void);

#endif
