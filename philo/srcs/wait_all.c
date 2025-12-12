/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 02:34:41 by avieira-          #+#    #+#             */
/*   Updated: 2025/12/12 02:34:46 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../include/philo.h"

bool	all_sat(t_mutex *mutex, long *threads, long philo_n)
{
	bool	ret;

	ret = false;
	while (ret == false)
	{
		mutex_handle(mutex, LOCK);
		if (*threads == philo_n)
			ret = true;
		mutex_handle(mutex, UNLOCK);
		usleep(1);
	}
	return (ret);
}

void	increase_long(t_mutex *mutex, long *value)
{
	mutex_handle(mutex, LOCK);
	(*value)++;
	mutex_handle(mutex, UNLOCK);
}

int	wait_all(t_philo *philo)
{
	while (get_bool(&philo->feast->wait, &philo->feast->rules.wait))
	{
		if (get_bool(&philo->feast->death, &philo->feast->end) == true)
			return (1);
		usleep(10);
	}
	return (0);
}
