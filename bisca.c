/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bisca.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 08:46:55 by avieira-          #+#    #+#             */
/*   Updated: 2025/10/02 19:31:53 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_play
{
    pthread_mutex_t start;
    pthread_mutex_t deck;
    bool            deck_open;
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

void    value_card_get(t_play *play, int *value)
{
    if (play->queens == 0 && play->kings > 0)
        *value = 1;
    else if (play->kings == 0 && play->queens > 0)
        *value = 0;
    else
        *value = random() % 2;
}

void    *my_turn(void *arg)
{
    int     value;
    char    *card;
    t_play  *play;

    printf("entered thread1\n");
    sleep(1);
    play = (t_play *) arg;
    pthread_mutex_lock(&play->start);
    pthread_mutex_unlock(&play->start);
    while (1)
    {
        pthread_mutex_lock(&play->deck);
        pthread_mutex_unlock(&play->deck);
        while (play->deck_open == false)
        {}
        value_card_get(play, &value);
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
        else if (play->queens == 0 && play->kings == 0)
        {
            pthread_mutex_unlock(&play->deck);
            break;
        }
        printf("I draw %s!\n", card);
        play->player_1_score += play->player_1_round;
        usleep(play->wait_time);
    }
    return (NULL);
}

void   *your_turn(void *arg)
{
    int     value;
    char    *card;
    t_play  *play;

    printf("entered thread 2!\n");
    sleep(1);
    play = (t_play *) arg;
    pthread_mutex_lock(&play->start);
    pthread_mutex_unlock(&play->start);
    while (1)
    {
        pthread_mutex_lock(&play->deck);
        value_card_get(play, &value);
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
        else if (play->queens == 0 && play->kings == 0)
        {
            pthread_mutex_unlock(&play->deck);
            break;
        }
        printf("You draw %s!\n", card);
        play->player_2_score += play->player_2_round;
        pthread_mutex_unlock(&play->deck);
        usleep(play->wait_time);
    }
    return (NULL);
}

void    winner_round_print(t_play *play, int round)
{
    if (play->player_1_round > play->player_2_round)
        printf("player 1 wins round %i\n", round);
    else if (play->player_2_round > play->player_1_round)
        printf("player 2 wins round %i\n", round);
    else if (play->player_1_round == play->player_2_round)
        printf("It's a draw in round %i\n", round);
}

void    winner_game_print(t_play *play)
{
    if (play->player_1_score > play->player_2_score)
        printf("player 1 wins the game\n");
    else if (play->player_2_score > play->player_1_score)
        printf("player 2 wins the game\n");
    else if (play->player_1_score == play->player_2_score)
        printf("The game is tied\n");
}

void    *game_result_get(void *arg)
{
    int     i;
    t_play  *play;

    printf("entered thread 3!\n");
    play = (t_play *) arg;
    pthread_mutex_lock(&play->start);
    pthread_mutex_unlock(&play->start);
    sleep(1);
    i = 0;
    while(1)
    {
        i++;
        sleep(1);
        pthread_mutex_lock(&play->deck);
        printf("queens = %i\n kings= %i\n", play->queens, play->kings);
        if (i < 4)
            winner_round_print(play, i);
        if (i == 4)
        {
            winner_game_print(play);
            pthread_mutex_unlock(&play->deck);
            break;
        }
        pthread_mutex_unlock(&play->deck);
    }
    return (NULL);
}

void    game_init(t_play *play, char *argv1)
{
    pthread_mutex_init(&play->start, NULL);
    pthread_mutex_init(&play->deck, NULL);
    play->deck_open = true;
    play->queens = 4;
    play->kings = 4;
    play->player_1_round = 0;
    play->player_2_round = 0;
    play->player_1_score = 0;
    play->player_2_score = 0;
    play->wait_time = ft_atoi(argv1);
}

void    threads_create(t_play *play)
{
    pthread_t   new_thread;
    pthread_t   new_thread2;
    pthread_t   new_thread3;

    pthread_mutex_lock(&play->start);
    pthread_create(&new_thread, NULL, my_turn, play);
    printf("thread1\n");
    pthread_create(&new_thread2, NULL, your_turn, play);
    printf("thread2\n");
    pthread_create(&new_thread3, NULL, game_result_get, play);
    printf("thread3\n");
    pthread_mutex_unlock(&play->start);
    pthread_join(new_thread, NULL);
    pthread_join(new_thread2, NULL);
    pthread_join(new_thread3, NULL);
    pthread_mutex_destroy(&play->start);
    pthread_mutex_destroy(&play->deck);
}

int main(int argc, char **argv)
{
    int         i;
    t_play fd     play;

    if (argc != 2)
        return (1);
    game_init(&play, argv[1]);
    threads_create(&play);
}
