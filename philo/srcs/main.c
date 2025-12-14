/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 02:32:54 by avieira-          #+#    #+#             */
/*   Updated: 2025/12/14 14:56:45 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../include/philo.h"

int	main(int argc, char **argv)
{
	int		error_code;
	int		return_code;
	t_feast	feast;

	if (argc != 5 && argc != 6)
	{
		write(2, MSG_USAGE, ft_strlen(MSG_USAGE));
		return (1);
	}
	if (parse(argc, argv) == -1)
		return (1);
	if (argc == 6 && ft_atol(argv[5]) == 0)
		return (0);
	error_code = feast_init(&feast, argc, argv);
	if (error_code != 0)
		return (error_return(&feast, 1, error_code));
	if (feast.rules.ph_n == 1)
		return_code = monologue_begin(&feast);
	else
		return_code = feast_begin(&feast);
	error_return(&feast, return_code, feast.rules.ph_n * 2 + 6);
}
