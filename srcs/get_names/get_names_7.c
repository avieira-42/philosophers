/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_names_7.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 03:53:56 by avieira-          #+#    #+#             */
/*   Updated: 2025/12/05 04:31:06 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_names.h"

void	convert_names_34(int number, char **str)
{
	if (number == 298)
		*str = "Niklas_Luhmann";
	else if (number == 299)
		*str = "Hartmut_Rosa";
	else if (number == 300)
		*str = "Peter_Winch";
	else if (number == 301)
		*str = "Basil_Mitchell";
	else if (number == 302)
		*str = "Ian_Hacking";
	else if (number == 303)
		*str = "Jonathan_Dancy";
	else if (number == 304)
		*str = "Simon_Blackburn";
	else if (number == 305)
		*str = "Stephen_Toulmin";
	else if (number == 306)
		*str = "Francis_Edgeworth";
	else
		convert_names_35(number, str);
}

void	convert_names_33(int number, char **str)
{
	if (number == 289)
		*str = "Benjamin_Constant";
	else if (number == 290)
		*str = "Olympe_de_Gouges";
	else if (number == 291)
		*str = "Mary_Wollstonecraft";
	else if (number == 292)
		*str = "Harriet_Taylor_Mill";
	else if (number == 293)
		*str = "John_Wesley";
	else if (number == 294)
		*str = "Gregory_Palamas";
	else if (number == 295)
		*str = "Arnold_Gehlen";
	else if (number == 296)
		*str = "Gunter_Abel";
	else if (number == 297)
		*str = "Helmut_Plessner";
	else
		convert_names_34(number, str);
}

void	convert_names_32(int number, char **str)
{
	if (number == 280)
		*str = "Paul_Tillich";
	else if (number == 281)
		*str = "St_Irenaeus";
	else if (number == 282)
		*str = "St_Basil";
	else if (number == 283)
		*str = "Gregory_of_Nyssa";
	else if (number == 284)
		*str = "John_Damascene";
	else if (number == 285)
		*str = "Albert_the_Great";
	else if (number == 286)
		*str = "Duns_Scotus";
	else if (number == 287)
		*str = "William_Tyndale";
	else if (number == 288)
		*str = "Johann_Gottfried_Herder";
	else
		convert_names_33(number, str);
}

void	convert_names_31(int number, char **str)
{
	if (number == 271)
		*str = "Frederick_Copleston";
	else if (number == 272)
		*str = "Alfred_J_Ayer";
	else if (number == 273)
		*str = "Richard_Rorty";
	else if (number == 274)
		*str = "John_McDowell";
	else if (number == 275)
		*str = "Thomas_Metzinger";
	else if (number == 276)
		*str = "John_Hickey";
	else if (number == 277)
		*str = "Eli_Pariser";
	else if (number == 278)
		*str = "Hans_Morgenthau";
	else if (number == 279)
		*str = "Reinhold_Niebuhr";
	else
		convert_names_32(number, str);
}
