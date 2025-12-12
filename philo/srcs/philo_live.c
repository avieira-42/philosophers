/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_live.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 02:39:09 by avieira-          #+#    #+#             */
/*   Updated: 2025/12/12 13:24:24 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../include/philo.h"

static inline
	void	thinking(t_philo *philo)
{
	long	t_eat;
	long	t_sleep;
	long	t_think;

	state_write(THINKING, philo->feast, philo->n - 1);
	if (philo->feast->rules.ph_n % 2 == 0)
		return ;
	t_eat = philo->feast->rules.time_to_eat;
	t_sleep = philo->feast->rules.time_to_sleep;
	t_think = t_eat * 2 - t_sleep;
	if (t_think < 0)
		t_think = 0;
	precise_usleep(t_think * 0.42, philo);
}

static inline
	void	sleeping(t_philo *philo)
{
	state_write(SLEEPING, philo->feast, philo->n - 1);
	precise_usleep(philo->feast->rules.time_to_sleep, philo);
}

#include <stdio.h>
static inline
	void	eating(t_philo *philo)
{
	mutex_handle(philo->first_fork, LOCK);
	state_write(TOOK_FIRST_FORK, philo->feast, philo->n - 1);
	mutex_handle(philo->second_fork, LOCK);
	state_write(TOOK_SECOND_FORK, philo->feast, philo->n - 1);
	state_write(EATING, philo->feast, philo->n - 1);
	set_long(&philo->mutex, &philo->last_meal, time_get());
	precise_usleep(philo->feast->rules.time_to_eat, philo);
	philo->meals++;
	if (philo->feast->rules.meals_max > 0
		&& philo->meals == philo->feast->rules.meals_max
		&& philo->bloated == false)
	{
		set_bool(&philo->mutex, &philo->bloated, true);
		increase_long(&philo->feast->bloated_count_mtx,
				&philo->feast->bloated_count);
	}
	mutex_handle(philo->first_fork, UNLOCK);
	mutex_handle(philo->second_fork, UNLOCK);
}

void	*essay_write(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (wait_all(philo) != 0)
		return (NULL);
	set_long(&philo->mutex, &philo->last_meal, philo->feast->rules.start);
	state_write(TOOK_FIRST_FORK, philo->feast, philo->n - 1);
	increase_long(&philo->feast->mutex, &philo->feast->threads_run_n);
	precise_usleep(philo->feast->rules.time_to_die, philo);
	return (NULL);
}

void	*philo_live(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (wait_all(philo) != 0)
		return (NULL);
	set_long(&philo->mutex, &philo->last_meal, philo->feast->rules.start);
	increase_long(&philo->feast->mutex, &philo->feast->threads_run_n);
	while (!feast_ended(&philo->feast->death, &philo->feast->end,
				&philo->feast->bloated, &philo->feast->full))
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
