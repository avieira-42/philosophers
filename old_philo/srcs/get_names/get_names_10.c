/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_names_10.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 03:48:28 by avieira-          #+#    #+#             */
/*   Updated: 2025/12/05 03:48:53 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_names.h"

void	convert_names_46(int number, char **str)
{
	if (number == 406)
		*str = "Philo_of_Alexandria";
	else if (number == 407)
		*str = "Longinus";
	else if (number == 408)
		*str = "Ammonius_Saccas";
	else if (number == 409)
		*str = "Hypatia_of_Alexandria";
	else if (number == 410)
		*str = "Proclus_Lycius";
	else if (number == 411)
		*str = "Damascius";
	else if (number == 412)
		*str = "John_Philloponus";
	else if (number == 413)
		*str = "Anicius_Boethius";
	else if (number == 414)
		*str = "Ockham_John";
	else
		convert_names_47(number, str);
}

void	convert_names_45(int number, char **str)
{
	if (number == 397)
		*str = "Alexis_de_Tocqueville";
	else if (number == 398)
		*str = "Edith_Stein";
	else if (number == 399)
		*str = "Simone_Weil";
	else if (number == 400)
		*str = "G_Lessing";
	else if (number == 401)
		*str = "John_Calvin";
	else if (number == 402)
		*str = "Martin_Luther";
	else if (number == 403)
		*str = "Albertus_Magnus";
	else if (number == 404)
		*str = "Origen_of_Alexandria";
	else if (number == 405)
		*str = "Clement_of_Alexandria";
	else
		convert_names_46(number, str);
}

void	convert_names_44(int number, char **str)
{
	if (number == 388)
		*str = "Charles_De_Koninck";
	else if (number == 389)
		*str = "Jean_Bodin";
	else if (number == 390)
		*str = "Voltaire";
	else if (number == 391)
		*str = "Montesquieu";
	else if (number == 392)
		*str = "Condorcet";
	else if (number == 393)
		*str = "La_Rochefoucauld";
	else if (number == 394)
		*str = "Pierre_Bayle";
	else if (number == 395)
		*str = "Helvetius";
	else if (number == 396)
		*str = "Madame_de_Stael";
	else
		convert_names_45(number, str);
}

void	convert_names_43(int number, char **str)
{
	if (number == 379)
		*str = "Henry_Home";
	else if (number == 380)
		*str = "Bonaventure";
	else if (number == 381)
		*str = "William_Langland";
	else if (number == 382)
		*str = "Thomas_Morus";
	else if (number == 383)
		*str = "Desiderius_Erasmus";
	else if (number == 384)
		*str = "Justus_Lipsius";
	else if (number == 385)
		*str = "Petrus_Ramus";
	else if (number == 386)
		*str = "Carl_Schmitt";
	else if (number == 387)
		*str = "Michael_Oakeshott";
	else
		convert_names_44(number, str);
}

void	convert_names_42(int number, char **str)
{
	if (number == 370)
		*str = "Hermann_Cohen";
	else if (number == 371)
		*str = "Paul_Natorp";
	else if (number == 372)
		*str = "Arthur_O_Lovejoy";
	else if (number == 373)
		*str = "Chauncey_Wright";
	else if (number == 374)
		*str = "Joseph_Butler";
	else if (number == 375)
		*str = "George_Eliot";
	else if (number == 376)
		*str = "Thomas_Brown";
	else if (number == 377)
		*str = "Adam_Ferguson";
	else if (number == 378)
		*str = "James_Harrington";
	else
		convert_names_43(number, str);
}
