/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_names_12.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 03:48:56 by avieira-          #+#    #+#             */
/*   Updated: 2025/12/05 04:06:12 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_names.h"

void	convert_names_56(int number, char **str)
{
	if (number == 496)
		*str = "Tamara_Tubb";
	else if (number == 497)
		*str = "Candice_Vogler";
	else if (number == 498)
		*str = "Richard_Boyd";
	else if (number == 499)
		*str = "Richard_Dawkins";
	else if (number == 500)
		*str = "Susan_Sontag";
	else
		*str = "Tiburcio";
}

void	convert_names_55(int number, char **str)
{
	if (number == 487)
		*str = "Brian_Leftow";
	else if (number == 488)
		*str = "Michael_Dummett";
	else if (number == 489)
		*str = "Robert_Adams";
	else if (number == 490)
		*str = "Alvin_Goldman";
	else if (number == 491)
		*str = "Ernest_Sosa";
	else if (number == 492)
		*str = "Linda_Zagzebski";
	else if (number == 493)
		*str = "Michael_Williams";
	else if (number == 494)
		*str = "Barry_Stroud";
	else if (number == 495)
		*str = "Gary_Marx";
	else
		convert_names_56(number, str);
}

void	convert_names_54(int number, char **str)
{
	if (number == 478)
		*str = "John_Rorty";
	else if (number == 479)
		*str = "Hans_Ulrich_Gumbrecht";
	else if (number == 480)
		*str = "Thomas_Pogge";
	else if (number == 481)
		*str = "Seana_Shreffrin";
	else if (number == 482)
		*str = "Amie_Thomasson";
	else if (number == 483)
		*str = "Susan_Haack";
	else if (number == 484)
		*str = "Ruth_Millikan";
	else if (number == 485)
		*str = "Cheryl_Misak";
	else if (number == 486)
		*str = "Peter_Geach";
	else
		convert_names_55(number, str);
}

void	convert_names_53(int number, char **str)
{
	if (number == 469)
		*str = "Kai_Nielsen";
	else if (number == 470)
		*str = "Walter_Benjamin";
	else if (number == 471)
		*str = "George_Bataille";
	else if (number == 472)
		*str = "Michel_de_Montaigne";
	else if (number == 473)
		*str = "Etienne_de_La_Boitie";
	else if (number == 474)
		*str = "Pierre_Hadot";
	else if (number == 475)
		*str = "Agnieszka_Nogal";
	else if (number == 476)
		*str = "Jean_Cottin";
	else if (number == 477)
		*str = "Stanley_Cavell";
	else
		convert_names_54(number, str);
}

void	convert_names_52(int number, char **str)
{
	if (number == 460)
		*str = "Erik_Olin_Wright";
	else if (number == 461)
		*str = "Robert_Brenner";
	else if (number == 462)
		*str = "Michael_Hardt";
	else if (number == 463)
		*str = "Henri_Lefebvre";
	else if (number == 464)
		*str = "Guy_Debord";
	else if (number == 465)
		*str = "Raoul_Vaneigem";
	else if (number == 466)
		*str = "Cornelius_Castoriadis";
	else if (number == 467)
		*str = "Christopher_Lasch";
	else if (number == 468)
		*str = "Gerald_Cohen";
	else
		convert_names_53(number, str);
}
