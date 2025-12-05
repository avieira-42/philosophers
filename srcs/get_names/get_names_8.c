/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_names_8.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 03:56:55 by avieira-          #+#    #+#             */
/*   Updated: 2025/12/05 04:33:29 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_names.h"

void	convert_names_37(int number, char **str)
{
	if (number == 325)
		*str = "Rosi_Braidotti";
	else if (number == 326)
		*str = "Valerie_Solanas";
	else if (number == 327)
		*str = "Elaine_Morgan";
	else if (number == 328)
		*str = "Luce_Irigaray";
	else if (number == 329)
		*str = "Bell_Hooks";
	else if (number == 330)
		*str = "Claudia_Card";
	else if (number == 331)
		*str = "Sally_Haslanger";
	else if (number == 332)
		*str = "Amia_Srinivasan";
	else if (number == 333)
		*str = "Kwame_Anthony_Appiah";
	else
		convert_names_38(number, str);
}

void	convert_names_36(int number, char **str)
{
	if (number == 316)
		*str = "Boris_Pasternak";
	else if (number == 317)
		*str = "Karl_Korsch";
	else if (number == 318)
		*str = "Rosa_Luxemburg";
	else if (number == 319)
		*str = "Georg_Lukacs";
	else if (number == 320)
		*str = "Antonio_Negri";
	else if (number == 321)
		*str = "Sylvia_Pankhurst";
	else if (number == 322)
		*str = "Angela_Davis";
	else if (number == 323)
		*str = "Donna_Haraway";
	else if (number == 324)
		*str = "Karen_Barodt";
	else
		convert_names_37(number, str);
}

void convert_names_20(int number, char **str)
{
    if (number == 172)
        *str = "Ibn_Arabi";
    else if (number == 173)
        *str = "Suhrawardi";
    else if (number == 174)
        *str = "Mulla_Sadra";
    else if (number == 175)
        *str = "Jalal_ad_Din_Rumi";
    else if (number == 176)
        *str = "Al_Biruni";
    else if (number == 177)
        *str = "Al_Kindi";
    else if (number == 178)
        *str = "Ahmad_Sirahindi";
    else if (number == 179)
        *str = "Farabi";
    else if (number == 180)
        *str = "Nishapur_Fakhr_al_Din_Razi";
    else
        convert_names_21(number, str);
}

void convert_names_17(int number, char **str)
{
    if (number == 145)
        *str = "Okakura_Kakuzo";
    else if (number == 146)
        *str = "Sun_Tzu";
    else if (number == 147)
        *str = "Laozi";
    else if (number == 148)
        *str = "Zhuangzi";
    else if (number == 149)
        *str = "Mencius";
    else if (number == 150)
        *str = "Mozi";
    else if (number == 151)
        *str = "Han_Feizi";
    else if (number == 152)
        *str = "Xunzi";
    else if (number == 153)
        *str = "Wang_Yangming";
    else
        convert_names_18(number, str);
}

void convert_names_35(int number, char **str)
{
    if (number == 307)
        *str = "Johann_Hari";
    else if (number == 308)
        *str = "Elaine_Scary";
    else if (number == 309)
        *str = "Luc_Ferry";
    else if (number == 310)
        *str = "Peter_Wolfendale";
    else if (number == 311)
        *str = "Henry_Sidgwick";
    else if (number == 312)
        *str = "Leszek_Kolakowski";
    else if (number == 313)
        *str = "Mikhail_Bakhtin";
    else if (number == 314)
        *str = "Vasily_Rozanov";
    else if (number == 315)
        *str = "Lev_Shostakov";
    else
        convert_names_36(number, str);
}
