/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_names_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 03:52:58 by avieira-          #+#    #+#             */
/*   Updated: 2025/12/05 03:53:10 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_names.h"

void	convert_names_25(int number, char **str)
{
	if (number == 217)
		*str = "Ray_Brassier";
	else if (number == 218)
		*str = "Nick_Land";
	else if (number == 219)
		*str = "Catherine_Malabou";
	else if (number == 220)
		*str = "Reza_Negarestani";
	else if (number == 221)
		*str = "Avital_Ronell";
	else if (number == 222)
		*str = "Peter_Sloterdijk";
	else if (number == 223)
		*str = "Bernard_Stiegler";
	else if (number == 224)
		*str = "François_Laruelle";
	else if (number == 225)
		*str = "Edgar_Morin";
	else
		convert_names_26(number, str);
}

void	convert_names_24(int number, char **str)
{
	if (number == 208)
		*str = "Bernard_Williams";
	else if (number == 209)
		*str = "Michael_Sandell";
	else if (number == 210)
		*str = "Robert_Audi";
	else if (number == 211)
		*str = "Anthony_Kenny";
	else if (number == 212)
		*str = "Timothy_Williamson";
	else if (number == 213)
		*str = "Graham_Harman";
	else if (number == 214)
		*str = "Quentin_Meillassoux";
	else if (number == 215)
		*str = "Markus_Gabriel";
	else if (number == 216)
		*str = "Manuel_DeLanda";
	else
		convert_names_25(number, str);
}

void	convert_names_23(int number, char **str)
{
	if (number == 199)
		*str = "Kurt_Godel";
	else if (number == 200)
		*str = "Alfred_Tarski";
	else if (number == 201)
		*str = "Rudolf_Carnap";
	else if (number == 202)
		*str = "Hans_Reichenbach";
	else if (number == 203)
		*str = "Moritz_Schlick";
	else if (number == 204)
		*str = "Ernst_Mach";
	else if (number == 205)
		*str = "George_Santayana";
	else if (number == 206)
		*str = "John_Serle";
	else if (number == 207)
		*str = "Thomas_Nagel";
	else
		convert_names_24(number, str);
}

void	convert_names_22(int number, char **str)
{
	if (number == 190)
		*str = "Ludwig_Wittgenstein";
	else if (number == 191)
		*str = "G_Moore";
	else if (number == 192)
		*str = "R_Hare";
	else if (number == 193)
		*str = "P_Strawson";
	else if (number == 194)
		*str = "John_Austin";
	else if (number == 195)
		*str = "Alasdair_MacIntyre";
	else if (number == 196)
		*str = "Charles_Peirce";
	else if (number == 197)
		*str = "C_Lewis";
	else if (number == 198)
		*str = "Henri_Poincare";
	else
		convert_names_23(number, str);
}

void	convert_names_21(int number, char **str)
{
	if (number == 181)
		*str = "Henry_Bergson";
	else if (number == 182)
		*str = "George_Berkeley";
	else if (number == 183)
		*str = "Denis_Diderot";
	else if (number == 184)
		*str = "J_Winckelmann";
	else if (number == 185)
		*str = "Giambattista_Vico";
	else if (number == 186)
		*str = "Henry_More";
	else if (number == 187)
		*str = "Ralph_Cudworth";
	else if (number == 188)
		*str = "Alfred_North_Whitehead";
	else if (number == 189)
		*str = "Bertrand_Russell";
	else
		convert_names_22(number, str);
}
