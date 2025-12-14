/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_names_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 03:49:27 by avieira-          #+#    #+#             */
/*   Updated: 2025/12/05 04:24:46 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_names.h"

void	convert_names_10(int number, char **str)
{
	if (number == 82)
		*str = "Jacques_Lacan";
	else if (number == 83)
		*str = "Paul_Ricoeur";
	else if (number == 84)
		*str = "Emmanuel_Levinas";
	else if (number == 85)
		*str = "Jean_Baudrillard";
	else if (number == 86)
		*str = "Roland_Barthes";
	else if (number == 87)
		*str = "Charles_Sanders_Peirce";
	else if (number == 88)
		*str = "William_James";
	else if (number == 89)
		*str = "John_Dewey";
	else if (number == 90)
		*str = "Charles_Taylor";
	else
		convert_names_11(number, str);
}

void	convert_names_9(int number, char **str)
{
	if (number == 73)
		*str = "Martin_Heidegger";
	else if (number == 74)
		*str = "Hannah_Arendt";
	else if (number == 75)
		*str = "Jean_Paul_Sartre";
	else if (number == 76)
		*str = "Maurice_Merleau_Ponty";
	else if (number == 77)
		*str = "Simone_de_Beauvoir";
	else if (number == 78)
		*str = "Albert_Camus";
	else if (number == 79)
		*str = "Gilles_Deleuze";
	else if (number == 80)
		*str = "Felix_Guattari";
	else if (number == 81)
		*str = "Jacques_Derrida";
	else
		convert_names_10(number, str);
}

void	convert_names_8(int number, char **str)
{
	if (number == 64)
		*str = "Gottfried_Leibniz";
	else if (number == 65)
		*str = "Christian_Wolff";
	else if (number == 66)
		*str = "Arthur_Schopenhauer";
	else if (number == 67)
		*str = "Friedrich_Nietzsche";
	else if (number == 68)
		*str = "Hegel";
	else if (number == 69)
		*str = "Johann_Fichte";
	else if (number == 70)
		*str = "Schelling";
	else if (number == 71)
		*str = "Soren_Kierkegaard";
	else if (number == 72)
		*str = "Edmund_Husserl";
	else
		convert_names_9(number, str);
}

void	convert_names_7(int number, char **str)
{
	if (number == 55)
		*str = "Thomas_Hobbes";
	else if (number == 56)
		*str = "Baruch_Spinoza";
	else if (number == 57)
		*str = "Francis_Bacon";
	else if (number == 58)
		*str = "John_Stuart_Mill";
	else if (number == 59)
		*str = "Jeremy_Bentham";
	else if (number == 60)
		*str = "Edmund_Burke";
	else if (number == 61)
		*str = "Adam_Smith";
	else if (number == 62)
		*str = "Thomas_Reid";
	else if (number == 63)
		*str = "Blaise_Pascal";
	else
		convert_names_8(number, str);
}

void	convert_names_6(int number, char **str)
{
	if (number == 46)
		*str = "Anselm_of_Canterbury";
	else if (number == 47)
		*str = "Peter_Abelard";
	else if (number == 48)
		*str = "William_of_Ockham";
	else if (number == 49)
		*str = "Avicenna";
	else if (number == 50)
		*str = "Al_Farabi";
	else if (number == 51)
		*str = "Al_Ghazali";
	else if (number == 52)
		*str = "Averroes";
	else if (number == 53)
		*str = "Maimonides";
	else if (number == 54)
		*str = "Niccolo_Machiavelli";
	else
		convert_names_7(number, str);
}
