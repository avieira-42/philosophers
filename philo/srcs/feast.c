/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feast.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 02:30:44 by avieira-          #+#    #+#             */
/*   Updated: 2025/12/12 02:31:04 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../include/philo.h"

static inline
	void	feast_celebrate(t_feast *feast, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		pthread_join(feast->philos[i].thread, NULL);
		i++;
	}
}

int	feast_begin(t_feast *feast)
{
	int			i;

	i = -1;
	while (++i < feast->rules.ph_n)
	{
		if (pthread_create(&feast->philos[i].thread,
				NULL, philo_live, &feast->philos[i]) == -1)
		{
			set_bool(&feast->mutex, &feast->end, true);
			return (feast_celebrate(feast, i), 2);
		}
	}
	if (pthread_create(&feast->death_collector,
			NULL, death_collector, feast) == -1)
	{
		set_bool(&feast->mutex, &feast->end, true);
		return (feast_celebrate(feast, feast->rules.ph_n), 2);
	}
	feast->rules.start = time_get();
	set_bool(&feast->wait, &feast->rules.wait, false);
	feast_celebrate(feast, feast->rules.ph_n);
	set_bool(&feast->mutex, &feast->end, true);
	pthread_join(feast->death_collector, NULL);
	return (0);
}

int	monologue_begin(t_feast *feast)
{
	int			i;

	i = 0;
	if (pthread_create(&feast->philos[i].thread,
			NULL, essay_write, &feast->philos[i]) == -1)
	{
		set_bool(&feast->mutex, &feast->end, true);
		return (feast_celebrate(feast, i), 2);
	}
	if (pthread_create(&feast->death_collector,
			NULL, death_collector, feast) == -1)
	{
		set_bool(&feast->mutex, &feast->end, true);
		return (feast_celebrate(feast, feast->rules.ph_n), 2);
	}
	feast->rules.start = time_get();
	set_bool(&feast->wait, &feast->rules.wait, false);
	feast_celebrate(feast, feast->rules.ph_n);
	set_bool(&feast->mutex, &feast->end, true);
	pthread_join(feast->death_collector, NULL);
	return (0);
}
