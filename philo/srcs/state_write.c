/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_write.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 02:38:22 by avieira-          #+#    #+#             */
/*   Updated: 2025/12/12 12:50:54 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../include/philo.h"

static inline
	int	long_len(long n)
{
	int	len;

	len = 0;
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len + 1);
}

static inline
	void	write_long_to_buf(long n, char *buf, int len)
{
	if (n > 9)
		write_long_to_buf(n / 10, buf, len - 1);
	buf[len] = n % 10 + '0';
}

static inline
	void	lotoa(long n, char *buf, int *len)
{
	*len = long_len(n);
	write_long_to_buf(n, buf, *len - 1);
}

static inline
	void	fast_write(char *status_msg, t_philo *philo)
{
	int		i;
	int		msg_len;
	char	msg[100];

	lotoa(time_get() - philo->feast->rules.start, msg, &msg_len);
	i = 0;
	msg[msg_len++] = ' ';
	while (philo->id[i])
		msg[msg_len++] = philo->id[i++];
	i = 0;
	msg[msg_len++] = ' ';
	while (status_msg[i])
		msg[msg_len++] = status_msg[i++];
	write(1, msg, msg_len);
}

void	state_write(t_status status, t_feast *feast, int i)
{
	if (feast->philos[i].bloated == true)
		return ;
	mutex_handle(&feast->message, LOCK);
	if ((status == TOOK_FIRST_FORK || status == TOOK_SECOND_FORK)
		&& !feast_ended(&feast->death, &feast->end,
			&feast->bloated, &feast->full))
		fast_write(MSG_FORK, &feast->philos[i]);
	else if ((status == EATING) && !feast_ended(&feast->death, &feast->end,
			&feast->bloated, &feast->full))
		fast_write(MSG_EATING, &feast->philos[i]);
	else if ((status == SLEEPING) && !feast_ended(&feast->death, &feast->end,
			&feast->bloated, &feast->full))
		fast_write(MSG_SLEEPING, &feast->philos[i]);
	else if ((status == THINKING) && !feast_ended(&feast->death, &feast->end,
			&feast->bloated, &feast->full))
		fast_write(MSG_THINKING, &feast->philos[i]);
	else if ((status == EATING) && !feast_ended(&feast->death, &feast->end,
			&feast->bloated, &feast->full))
		fast_write(MSG_DIED, &feast->philos[i]);
	mutex_handle(&feast->message, UNLOCK);
}
