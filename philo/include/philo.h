#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>

# ifndef PHILO_MAX
#  define PHILO_MAX 200
# endif

typedef pthread_mutex_t	t_mutex;
typedef pthread_t		t_thread;

# define MSG_USAGE "./philo [philo_n] [time_to_die] [time_to_eat] [time_to_sleep] \
[max_meals](optional)\n"
# define MSG_USAGE_2 "Only positive numbers allowed\n"
# define MSG_FORK "has taken a fork\n"
# define MSG_EATING "is eating\n"
# define MSG_SLEEPING "is sleeping\n"
# define MSG_THINKING "is thinking\n"
# define MSG_DIED "died\n"

typedef struct s_feast t_feast;

typedef enum e_option
{
	INIT,
	CtrueREATE,
	DESTROY,
	LOCK,
	UNLOCK,
	JOIN,
	DETACH,
}	t_option;

typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	TOOK_FIRST_FORK,
	TOOK_SECOND_FORK,
	DIED,
}	t_status;

typedef struct s_rule
{
	int			victim;
	int			meals_max;
	int			ph_n;
	bool		wait;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long long	start;
}	t_rule;

typedef struct s_philo
{
	char		id[100];
	int			n;
	int			meals;
	long		last_meal;
	bool		bloated;
	t_mutex		*first_fork;
	t_mutex		*second_fork;
	t_thread	thread;
	t_feast		*feast;
	t_mutex		mutex;
}	t_philo;

struct s_feast
{
	bool		end;
	long		threads_run_n;
	t_rule		rules;
	t_mutex		message;
	t_mutex		death;
	t_mutex		wait;
	t_mutex		start;
	t_mutex		mutex;
	t_mutex		forks[PHILO_MAX];
	t_philo		philos[PHILO_MAX];
	t_thread	death_collector;
};

/*#######################      UTILS     ###########################*/
void		state_write(t_status status, t_feast *feast, int i);

/*#######################      PARSE     ###########################*/
int			parse(int argc, char **argv);

/*#######################       LIB      ###########################*/
long		ft_atol(char *nbr);
int			ft_strlen(char *str);
int			ft_is_digit(char c);
void		ft_itoa(int n, char *buf);

/*#######################   FEAST_INIT    ###########################*/
int			feast_init(t_feast *feast, int argc, char **argv);

/*#######################      FEAST      ###########################*/
int			feast_begin(t_feast *feast);

/*#######################     WAIT_ALL    ###########################*/
void		wait_all(t_philo *philo);
void		increase_long(t_mutex *mutex, long *value);
bool		all_sat(t_mutex *mutex, long *threads, long philo_n);

/*#######################      PHILO      ###########################*/
void		*philo_live(void *arg);

/*####################### DEATH_COLLECTOR ###########################*/
void		*death_collector(void *arg);

/*#######################    TIME_GET     ###########################*/
long long	time_get(void);

/*#######################  PRECISE_USLEEP ###########################*/
void		precise_usleep(long usec, t_philo *philo);

/*#######################      MUTEX      ###########################*/
void		mutex_handle(t_mutex *mutex, t_option option);

/*#######################  GETTER_SETTER  ###########################*/
void		set_bool(t_mutex *mutex, bool *dest, bool value);
bool		get_bool(t_mutex *mutex, bool *value);
void		set_long(t_mutex *mutex, long *dest, long value);
long		get_long(t_mutex *mutex, long *value);
bool		feast_ended(t_mutex *death, bool *end);

#endif
