/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 02:28:13 by avieira-          #+#    #+#             */
/*   Updated: 2025/12/12 02:28:14 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../include/philo.h"

int	error_return(t_feast *feast, int return_code, int error_code)
{
	int	i;

	if (error_code-- > 0)
		pthread_mutex_destroy(&feast->mutex);
	if (error_code-- > 0)
		pthread_mutex_destroy(&feast->wait);
	if (error_code-- > 0)
		pthread_mutex_destroy(&feast->message);
	if (error_code-- > 0)
		pthread_mutex_destroy(&feast->death);
	i = 0;
	while (i < feast->rules.ph_n && error_code-- > 0)
		pthread_mutex_destroy(&feast->forks[i++]);
	i = 0;
	while (i < feast->rules.ph_n && error_code-- > 0)
		pthread_mutex_destroy(&feast->philos[i++].mutex);
	if (return_code == 2)
		write(2, "Failed to create all philosopher threads\n", 41);
	return (return_code);
}
