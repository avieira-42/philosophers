/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 02:33:05 by avieira-          #+#    #+#             */
/*   Updated: 2025/12/12 02:33:05 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	mutex_handle(t_mutex *mutex, t_option option)
{
	if (option == LOCK)
		pthread_mutex_lock(mutex);
	else if (option == UNLOCK)
		pthread_mutex_unlock(mutex);
}
