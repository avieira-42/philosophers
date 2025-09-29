/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 08:46:55 by avieira-          #+#    #+#             */
/*   Updated: 2025/09/29 19:41:41 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_play
{
    int     queens;
    int     kings;
    int     wait_time;
}   t_play;

int	ft_atoi(const char *nptr)
{
	int				s;
	int				nb;
	unsigned int	i;

	s = 1;
	nb = 0;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '-')
	{
		s = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nptr[i] - '0' + nb * 10;
		i++;
	}
	return (nb * s);
}

void    *my_turn(void *arg)
{
    int     value;
    char    *card;
    t_play  *play;

    play = (t_play *) arg;
    while (1)
    {
        value = (random() % 2);
        if (value == 0 && play->queens > 0)
        {
            card = "queen";
            play->queens--;
        }
        else if (value == 1 && play->kings > 0)
        {
            card = "king";
            play->kings--;
        }
        printf("I draw %s!\n", card);
        if (play->queens == 0 && play->kings == 0)
            break;
        sleep(play->wait_time);
    }
    return (NULL);
}

void   *your_turn(void *arg)
{
    int     value;
    char    *card;
    t_play  *play;

    play = (t_play *) arg;
    while (1)
    {
        value = (random() % 2);
        if (value == 0 && play->queens > 0)
        {
            card = "queen";
            play->queens--;
        }
        else if (value == 1 && play->kings > 0)
        {
            card = "king";
            play->kings--;
        }
        if (play->queens == 0 && play->kings == 0)
            break;
        printf("You draw %s!\n", card);
        sleep(play->wait_time);
    }
    return (NULL);
}

int main(int argc, char **argv)
{
    int         i;
    t_play      play;
    pthread_t   new_thread;
    pthread_t   new_thread2;
    pthread_t   new_thread3;

    if (argc != 2)
        return (1);
    play.queens = 4;
    play.kings = 4;
    play.wait_time = ft_atoi(argv[1]);
    pthread_create(&new_thread, NULL, my_turn, &play);
    pthread_create(&new_thread2, NULL, your_turn, &play);

    pthread_join(new_thread, NULL);
    pthread_join(new_thread2, NULL);
}
