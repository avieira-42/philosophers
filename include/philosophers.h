/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 17:09:16 by avieira-          #+#    #+#             */
/*   Updated: 2025/10/02 19:29:52 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include <stdarg.h>
# include <fcntl.h>
# include <sys/time.h>
# include <pthread.h>

// PHILOSOPHER STRUCT
typedef struct philosopher

// PARSE MESSAGES
# define MSG_USE "Use: ./prog <philoNo> <dieTime> <sleepTime> <eatTimeNo>(op)\n"

// STATE MESSAGES

/* A displayed state message should not overlap with another message
 * A message announcing a p hilosopher's death must be displayed
 * within 10 ms of their actual death */

# define MSG_TAKEN_FORK "has taken a fork\n"
# define MSG_EATING "is eating\n"
# define MSG_SLEEPING "is sleeping\n"
# define MSG_THINKING "is thinking\n"
# define MSG_DIED "died\n"


void    error_exit(int error_code);

void    parse_arguments(int argc, char **argv);

void	ft_putstr_fd(char *s, int fd);

#endif
