/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_names_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 03:57:40 by avieira-          #+#    #+#             */
/*   Updated: 2025/12/05 04:24:40 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_names.h"

void	convert_names_30(int number, char **str)
{
	if (number == 262)
		*str = "Simeon_ben_Zemah_Duran";
	else if (number == 263)
		*str = "Francesco_Petrarch";
	else if (number == 264)
		*str = "Giovanni_Pico_della_Mirandola";
	else if (number == 265)
		*str = "Marsilio_Ficino";
	else if (number == 266)
		*str = "Girolamo_Cardano";
	else if (number == 267)
		*str = "Baldassare_Castiglione";
	else if (number == 268)
		*str = "Tommaso_Campanella";
	else if (number == 269)
		*str = "Giordano_Bruno";
	else if (number == 270)
		*str = "Francisco_Suarez";
	else
		convert_names_31(number, str);
}
