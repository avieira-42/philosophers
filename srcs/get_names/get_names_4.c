/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_names_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 03:52:45 by avieira-          #+#    #+#             */
/*   Updated: 2025/12/05 03:52:50 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_names.h"

void	convert_names_19(int number, char **str)
{
	if (number == 163)
		*str = "Carneades";
	else if (number == 164)
		*str = "Arcesilaus";
	else if (number == 165)
		*str = "Aenesidemus";
	else if (number == 166)
		*str = "Philolaus";
	else if (number == 167)
		*str = "Metrodorus_of_Chios";
	else if (number == 168)
		*str = "Cassiodorus";
	else if (number == 169)
		*str = "John_Scotus_Eriugena";
	else if (number == 170)
		*str = "Alcuin";
	else if (number == 171)
		*str = "Ibn_Khaldun";
	else
		convert_names_20(number, str);
}

void	convert_names_18(int number, char **str)
{
	if (number == 154)
		*str = "Zhu_Xi";
	else if (number == 155)
		*str = "Shen_Kua";
	else if (number == 156)
		*str = "Dong_Zhongshu";
	else if (number == 157)
		*str = "Chrysippus";
	else if (number == 158)
		*str = "Cleanthes";
	else if (number == 159)
		*str = "Posidonius";
	else if (number == 160)
		*str = "Arrian";
	else if (number == 161)
		*str = "Sextus_Empiricus";
	else if (number == 162)
		*str = "Pyrrho";
	else
		convert_names_19(number, str);
}

void	convert_names_16(int number, char **str)
{
	if (number == 136)
		*str = "Homi_Bhabha";
	else if (number == 137)
		*str = "Amartya_Sen";
	else if (number == 138)
		*str = "Muhammad_Iqbal";
	else if (number == 139)
		*str = "Tagore";
	else if (number == 140)
		*str = "Nishida_Kitaro";
	else if (number == 141)
		*str = "Tanabe_Hajime";
	else if (number == 142)
		*str = "Keiji_Nishitani";
	else if (number == 143)
		*str = "Watsuji_Tetsuro";
	else if (number == 144)
		*str = "Kuki_Shubun";
	else
		convert_names_17(number, str);
}
