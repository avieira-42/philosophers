/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_names_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 03:50:29 by avieira-          #+#    #+#             */
/*   Updated: 2025/12/05 03:50:56 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_names.h"

void	convert_names_15(int number, char **str)
{
	if (number == 127)
		*str = "Leo_Strauss";
	else if (number == 128)
		*str = "Allan_Bloom";
	else if (number == 129)
		*str = "Charles_Mills";
	else if (number == 130)
		*str = "Cornel_West";
	else if (number == 131)
		*str = "Frantz_Fanon";
	else if (number == 132)
		*str = "Ngugi_wa_Thiong_o";
	else if (number == 133)
		*str = "Edouard_Glissant";
	else if (number == 134)
		*str = "Sylvia_Wynter";
	else if (number == 135)
		*str = "Gayatri_Spivak";
	else
		convert_names_16(number, str);
}

void	convert_names_14(int number, char **str)
{
	if (number == 118)
		*str = "Gilbert_Ryle";
	else if (number == 119)
		*str = "Herbert_Marcuse";
	else if (number == 120)
		*str = "Max_Horkheimer";
	else if (number == 121)
		*str = "Theodor_Adorno";
	else if (number == 122)
		*str = "Erich_Fromm";
	else if (number == 123)
		*str = "Jurgen_Habermas";
	else if (number == 124)
		*str = "Axel_Honneth";
	else if (number == 125)
		*str = "Ernst_Cassirer";
	else if (number == 126)
		*str = "Isaiah_Berlin";
	else
		convert_names_15(number, str);
}

void	convert_names_13(int number, char **str)
{
	if (number == 109)
		*str = "Christine_Korsgaard";
	else if (number == 110)
		*str = "Martha_Nussbaum";
	else if (number == 111)
		*str = "Judith_Butler";
	else if (number == 112)
		*str = "Patricia_Churchland";
	else if (number == 113)
		*str = "Paul_Churchland";
	else if (number == 114)
		*str = "Alvin_Plantinga";
	else if (number == 115)
		*str = "Elizabeth_Anscombe";
	else if (number == 116)
		*str = "Philippa_Foot";
	else if (number == 117)
		*str = "Mary_Midgley";
	else
		convert_names_14(number, str);
}

void	convert_names_12(int number, char **str)
{
	if (number == 100)
		*str = "Imre_Lakatos";
	else if (number == 101)
		*str = "Norbert_Wiener";
	else if (number == 102)
		*str = "Hubert_Dreyfus";
	else if (number == 103)
		*str = "John_Searle";
	else if (number == 104)
		*str = "Jerry_Fodor";
	else if (number == 105)
		*str = "Ned_Block";
	else if (number == 106)
		*str = "Daniel_Dennett";
	else if (number == 107)
		*str = "Peter_Singer";
	else if (number == 108)
		*str = "Derek_Parfit";
	else
		convert_names_13(number, str);
}

void	convert_names_11(int number, char **str)
{
	if (number == 91)
		*str = "Wilfrid_Sellars";
	else if (number == 92)
		*str = "Donald_Davidson";
	else if (number == 93)
		*str = "Hilary_Putnam";
	else if (number == 94)
		*str = "Willard_Quine";
	else if (number == 95)
		*str = "Saul_Kripke";
	else if (number == 96)
		*str = "David_Lewis";
	else if (number == 97)
		*str = "Karl_Popper";
	else if (number == 98)
		*str = "Thomas_Kuhn";
	else if (number == 99)
		*str = "Paul_Feyerabend";
	else
		convert_names_12(number, str);
}
