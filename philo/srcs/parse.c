/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 02:33:37 by avieira-          #+#    #+#             */
/*   Updated: 2025/12/14 14:57:03 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../include/philo.h"

int	parse(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_is_digit(argv[i][j]) == -1)
			{
				write(2, MSG_USAGE_2, ft_strlen(MSG_USAGE_2));
				return (-1);
			}
			j++;
		}
		i++;
	}
	if (ft_atol(argv[1]) > PHILO_MAX)
	{
		write(2, "For more than 200 overthinkers redefine PHILO_MAX\n", 50);
		return (-1);
	}
	return (0);
}
