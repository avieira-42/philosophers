/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_names_11.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 03:48:25 by avieira-          #+#    #+#             */
/*   Updated: 2025/12/05 03:48:26 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_names.h"

void	convert_names_51(int number, char **str)
{
	if (number == 451)
		*str = "Pierre_Joseph_Proudhon";
	else if (number == 452)
		*str = "Mikhail_Bakunin";
	else if (number == 453)
		*str = "Peter_Kropotkin";
	else if (number == 454)
		*str = "Rudolf_Rocker";
	else if (number == 455)
		*str = "Gustav_Landauer";
	else if (number == 456)
		*str = "Emma_Goldman";
	else if (number == 457)
		*str = "Voltairine_de_Cleyre";
	else if (number == 458)
		*str = "Ursula_LeGuin";
	else if (number == 459)
		*str = "David_Harvey";
	else
		convert_names_52(number, str);
}

void	convert_names_50(int number, char **str)
{
	if (number == 442)
		*str = "John_Wycliffe";
	else if (number == 443)
		*str = "Felix_Mendelssohn";
	else if (number == 444)
		*str = "Jean_Meslier";
	else if (number == 445)
		*str = "André_Comte_Sponville";
	else if (number == 446)
		*str = "Lucien_Goldmann";
	else if (number == 447)
		*str = "Jean_Starobinski";
	else if (number == 448)
		*str = "Etienne_Balibar";
	else if (number == 449)
		*str = "Louis_Althusser";
	else if (number == 450)
		*str = "Claude_Henri_Saint_Simon";
	else
		convert_names_51(number, str);
}

void	convert_names_49(int number, char **str)
{
	if (number == 433)
		*str = "David_Alighieri";
	else if (number == 434)
		*str = "Novalis";
	else if (number == 435)
		*str = "Angelus_Silesius";
	else if (number == 436)
		*str = "Meister_Eckhart";
	else if (number == 437)
		*str = "Jakob_Boehme";
	else if (number == 438)
		*str = "Paracelsus";
	else if (number == 439)
		*str = "Caspar_Schwenckfeld";
	else if (number == 440)
		*str = "Bernard_of_Clairvaux";
	else if (number == 441)
		*str = "Jan_Hus";
	else
		convert_names_50(number, str);
}

void	convert_names_48(int number, char **str)
{
	if (number == 424)
		*str = "Enrique_Dussel";
	else if (number == 425)
		*str = "Rodolfo_Kusch";
	else if (number == 426)
		*str = "Paulo_Freire";
	else if (number == 427)
		*str = "Orlando_Fals_Borda";
	else if (number == 428)
		*str = "Arturo_Escobar";
	else if (number == 429)
		*str = "Mario_Bunge";
	else if (number == 430)
		*str = "Ernesto_Laclau";
	else if (number == 431)
		*str = "Chantal_Mouffe";
	else if (number == 432)
		*str = "Claude_Adrien_Helvetius";
	else
		convert_names_49(number, str);
}

void	convert_names_47(int number, char **str)
{
	if (number == 415)
		*str = "John_Duns_Scotus";
	else if (number == 416)
		*str = "Ibn_Rushd";
	else if (number == 417)
		*str = "Juan_de_Seconda";
	else if (number == 418)
		*str = "Francisco_de_Vitoria";
	else if (number == 419)
		*str = "Bartolome_de_Las_Casas";
	else if (number == 420)
		*str = "Sor_Juana_Ines_de_la_Cruz";
	else if (number == 421)
		*str = "Jorge_Portilla";
	else if (number == 422)
		*str = "Emilio_Uranga";
	else if (number == 423)
		*str = "Leopoldo_Zea";
	else
		convert_names_48(number, str);
}
