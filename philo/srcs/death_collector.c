/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_collector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 02:28:03 by avieira-          #+#    #+#             */
/*   Updated: 2025/12/12 14:24:27 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../include/philo.h"

static inline
	bool	philo_died(t_philo *philo)
{
	long	elapsed;
	long	t_to_die;

	elapsed = time_get() - get_long(&philo->mutex, &philo->last_meal);
	t_to_die = philo->feast->rules.time_to_die;
	if (elapsed >= t_to_die)
		return (true);
	return (false);
}

static inline
	bool	philos_full(t_feast *feast)
{
	bool	ret;

	ret = false;
	mutex_handle(&feast->bloated_count_mtx, LOCK);
	if (feast->bloated_count == feast->rules.ph_n)
		ret = true;
	mutex_handle(&feast->bloated_count_mtx, UNLOCK);
	return (ret);
}

void	*death_collector(void *arg)
{
	int		i;
	t_feast	*feast;

	feast = (t_feast *)arg;
	all_sat(&feast->mutex, &feast->threads_run_n, feast->rules.ph_n);
	while (!feast_ended(&feast->death, &feast->end,
			&feast->bloated, &feast->full))
	{
		if (philos_full(feast) == true)
			return (set_bool(&feast->bloated, &feast->full, true), NULL);
		i = -1;
		while (++i < feast->rules.ph_n)
		{
			if (philo_died(&feast->philos[i]))
			{
				state_write(DIED, feast, i);
				set_bool(&feast->death, &feast->end, true);
				return (NULL);
			}
		}
		usleep(500);
	}
	return (NULL);
}
