/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precise_usleep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 02:38:59 by avieira-          #+#    #+#             */
/*   Updated: 2025/12/12 02:39:07 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/time.h>
#include "../include/philo.h"

void	precise_usleep(long usec, t_philo *philo)
{
	long	start;

	start = time_get();
	while (time_get() - start <= usec)
	{
		if (feast_ended(&philo->feast->death, &philo->feast->end))
			break ;
		usleep(50);
	}
}
