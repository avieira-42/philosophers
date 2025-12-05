/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_names_6.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 03:53:22 by avieira-          #+#    #+#             */
/*   Updated: 2025/12/05 03:57:09 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_names.h"

void	convert_names_29(int number, char **str)
{
	if (number == 253)
		*str = "Hakuin_Ekaku";
	else if (number == 254)
		*str = "Mori_Ogai";
	else if (number == 255)
		*str = "Ibn_Tufail";
	else if (number == 256)
		*str = "Ibn_Bajja";
	else if (number == 257)
		*str = "Abu_Nasr_Al_Farabi";
	else if (number == 258)
		*str = "Biruni";
	else if (number == 259)
		*str = "Shahrastani";
	else if (number == 260)
		*str = "Isaac_Israeli";
	else if (number == 261)
		*str = "Hasdai_Crescas";
	else
		convert_names_30(number, str);
}

void	convert_names_28(int number, char **str)
{
	if (number == 244)
		*str = "Benedetto_Croce";
	else if (number == 245)
		*str = "Antonio_Gramsci";
	else if (number == 246)
		*str = "Umberto_Eco";
	else if (number == 247)
		*str = "Kenji_Miyazawa";
	else if (number == 248)
		*str = "Saichō";
	else if (number == 249)
		*str = "Kūkai";
	else if (number == 250)
		*str = "Dōgen";
	else if (number == 251)
		*str = "Shinran";
	else if (number == 252)
		*str = "Ryōkan";
	else
		convert_names_29(number, str);
}

void	convert_names_27(int number, char **str)
{
	if (number == 235)
		*str = "Hans_Georg_Gadamer";
	else if (number == 236)
		*str = "Hans_Jonas";
	else if (number == 237)
		*str = "Ernst_Bloch";
	else if (number == 238)
		*str = "Karl_Jaspers";
	else if (number == 239)
		*str = "Roman_Ingarden";
	else if (number == 240)
		*str = "Stanislaw_Lesiaw";
	else if (number == 241)
		*str = "Maria_Zambrano";
	else if (number == 242)
		*str = "Jose_Ortega_y_Gasset";
	else if (number == 243)
		*str = "Giovanni_Gentile";
	else
		convert_names_28(number, str);
}

void	convert_names_26(int number, char **str)
{
	if (number == 226)
		*str = "Jean_Luc_Nancy";
	else if (number == 227)
		*str = "Alain_Badiou";
	else if (number == 228)
		*str = "Michel_Serres";
	else if (number == 229)
		*str = "Gaston_Bachelard";
	else if (number == 230)
		*str = "Etienne_Gilson";
	else if (number == 231)
		*str = "Jean_Cavalier";
	else if (number == 232)
		*str = "Marcel_Mauss";
	else if (number == 233)
		*str = "Claude_Levi_Strauss";
	else if (number == 234)
		*str = "Max_Scheler";
	else
		convert_names_27(number, str);
}
