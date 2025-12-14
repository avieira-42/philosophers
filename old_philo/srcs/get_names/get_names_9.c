/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_names_9.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 03:56:42 by avieira-          #+#    #+#             */
/*   Updated: 2025/12/05 03:56:49 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_names.h"

void	convert_names_41(int number, char **str)
{
	if (number == 361)
		*str = "Robert_Brandon";
	else if (number == 362)
		*str = "Galen_Strawson";
	else if (number == 363)
		*str = "Kit_Fine";
	else if (number == 364)
		*str = "Stephen_Yablo";
	else if (number == 365)
		*str = "David_Chalmers";
	else if (number == 366)
		*str = "Jonathan_Schaefer";
	else if (number == 367)
		*str = "Ted_Sider";
	else if (number == 368)
		*str = "Karen_Bennett";
	else if (number == 369)
		*str = "Manfred_Stassen";
	else
		convert_names_42(number, str);
}

void	convert_names_40(int number, char **str)
{
	if (number == 352)
		*str = "Azariah_dei_Rossi";
	else if (number == 353)
		*str = "Hugo_Grotius";
	else if (number == 354)
		*str = "Samuel_Pufendorf";
	else if (number == 355)
		*str = "Christian_Thomasius";
	else if (number == 356)
		*str = "Gerard_Manley_Hopkins";
	else if (number == 357)
		*str = "Colin_McGinn";
	else if (number == 358)
		*str = "Richard_Swinburne";
	else if (number == 359)
		*str = "John_Hick";
	else if (number == 360)
		*str = "George_Edward_Moore";
	else
		convert_names_41(number, str);
}

void	convert_names_39(int number, char **str)
{
	if (number == 343)
		*str = "Ubuntu_Desmond";
	else if (number == 344)
		*str = "Shaykh_Ahmad";
	else if (number == 345)
		*str = "Rumi_Sadr";
	else if (number == 346)
		*str = "Al_Kashani";
	else if (number == 347)
		*str = "Fakhr_ad_Din_Razi";
	else if (number == 348)
		*str = "Ghazali_II";
	else if (number == 349)
		*str = "Mulla_Fatemi";
	else if (number == 350)
		*str = "Moses_Narboni";
	else if (number == 351)
		*str = "Judah_Halevi";
	else
		convert_names_40(number, str);
}

void	convert_names_38(int number, char **str)
{
	if (number == 334)
		*str = "Henry_Gates_Jr";
	else if (number == 335)
		*str = "Anthony_Pinn";
	else if (number == 336)
		*str = "John_Mbiti";
	else if (number == 337)
		*str = "Wiredu_Kwasi";
	else if (number == 338)
		*str = "Tsenay_Serequeberhan";
	else if (number == 339)
		*str = "Lewis_Gordon";
	else if (number == 340)
		*str = "Mogobe_Ramose";
	else if (number == 341)
		*str = "Pauline_Hountondji";
	else if (number == 342)
		*str = "Okot_p_Bitek";
	else
		convert_names_39(number, str);
}
