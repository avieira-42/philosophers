/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 08:46:55 by avieira-          #+#    #+#             */
/*   Updated: 2025/09/30 14:30:25 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_play
{
    pthread_mutex_t deck;
    int             queens;
    int             kings;
    int             wait_time;
    int             player_1_round;
    int             player_2_round;
    int             player_1_score;
    int             player_2_score;
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
        pthread_mutex_lock(&play->deck);
        value = (random() % 2);
        if (value == 0 && play->queens > 0)
        {
            card = "queen";
            play->queens--;
            play->player_1_round = 5;
        }
        else if (value == 1 && play->kings > 0)
        {
            card = "king";
            play->kings--;
            play->player_1_round = 10;
        }
        printf("I draw %s!\n", card);
        play->player_1_score += play->player_1_round;
        if (play->queens == 0 && play->kings == 0)
            break;
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
        pthread_mutex_lock(&play->deck);
        value = (random() % 2);
        if (value == 0 && play->queens > 0)
        {
            card = "queen";
            play->queens--;
            play->player_2_round = 5;
        }
        else if (value == 1 && play->kings > 0)
        {
            card = "king";
            play->kings--;
            play->player_2_round = 10;
        }
        printf("You draw %s!\n", card);
        play->player_1_score += play->player_1_round;
        if (play->queens == 0 && play->kings == 0)
            break;
    }
    return (NULL);
}

void    *game_result_get(void *arg)
{
    int     i;
    t_play  *play;

    play = (t_play *) arg;
    i = 0;
    while(1)
    {
        sleep(play->wait_time);
        pthread_mutex_lock(&play->deck);
        if (i < 4)
        {
            if (play->player_1_round > play->player_2_round)
                printf("player 1 wins round %i\n", i);
            else if (play->player_2_round > play->player_1_round)
                printf("player 2 wins round %i\n", i);
            else if (play->player_1_round == play->player_2_round)
                printf("It's a draw in round %i", i);
        }
        if (i == 4)
        {
            if (play->player_1_score > play->player_2_score)
                printf("player 1 wins the game");
            else if (play->player_2_score > play->player_1_score)
                printf("player 2 wins the game");
            else if (play->player_1_score == play->player_2_score)
                printf("The game is tied");
            break;
        }
        i++;
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
    play.player_1_round = 0;
    play.player_2_round = 0;
    play.player_1_score = 0;
    play.player_2_score = 0;
    play.wait_time = ft_atoi(argv[1]);
    pthread_create(&new_thread, NULL, my_turn, &play);
    pthread_create(&new_thread2, NULL, your_turn, &play);
    pthread_create(&new_thread3, NULL, game_result_get, &play);
    pthread_join(new_thread, NULL);
    pthread_join(new_thread2, NULL);
    pthread_join(new_thread3, NULL);
}
