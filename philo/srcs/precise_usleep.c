#include <unistd.h>
#include <sys/time.h>
#include "../include/philo.h"

void	precise_usleep(long usec, t_philo *philo)
{
	long	start;
	long	elapsed;
	long	remaining;

	start = time_get();
	while (time_get() - start < usec)
	{
		if (feast_ended(&philo->feast->death, &philo->feast->end))
			break;
		elapsed = time_get() - start;
		remaining = usec - elapsed;
		(void) remaining;
		if (remaining > 1000)
			usleep(remaining / 2);
	}
}
