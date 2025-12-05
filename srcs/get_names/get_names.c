/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_names.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 03:57:49 by avieira-          #+#    #+#             */
/*   Updated: 2025/12/05 04:05:29 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_names.h"

void	convert_names_5(int number, char **str)
{
	if (number == 37)
		*str = "Epictetus";
	else if (number == 38)
		*str = "Cicero";
	else if (number == 39)
		*str = "Plotinus";
	else if (number == 40)
		*str = "Porphyry";
	else if (number == 41)
		*str = "Iamblichus";
	else if (number == 42)
		*str = "Proclus";
	else if (number == 43)
		*str = "Boethius";
	else if (number == 44)
		*str = "Augustine_of_Hippo";
	else if (number == 45)
		*str = "Thomas_Aquinas";
	else
		convert_names_6(number, str);
}

void	convert_names_4(int number, char **str)
{
	if (number == 28)
		*str = "Gorgias";
	else if (number == 29)
		*str = "Zeno_of_Elea";
	else if (number == 30)
		*str = "Diogenes_of_Sinope";
	else if (number == 31)
		*str = "Antisthenes";
	else if (number == 32)
		*str = "Crates_of_Thebes";
	else if (number == 33)
		*str = "Epicurus";
	else if (number == 34)
		*str = "Lucretius";
	else if (number == 35)
		*str = "Marcus_Aurelius";
	else if (number == 36)
		*str = "Seneca";
	else
		convert_names_5(number, str);
}

void	convert_names_3(int number, char **str)
{
	if (number == 19)
		*str = "Byung_Chul_Han";
	else if (number == 20)
		*str = "Thales_of_Miletus";
	else if (number == 21)
		*str = "Heraclitus";
	else if (number == 22)
		*str = "Parmenides";
	else if (number == 23)
		*str = "Empedocles";
	else if (number == 24)
		*str = "Anaxagoras";
	else if (number == 25)
		*str = "Leucippus";
	else if (number == 26)
		*str = "Democritus";
	else if (number == 27)
		*str = "Protagoras";
	else
		convert_names_4(number, str);
}

void	convert_names_2(int number, char **str)
{
	if (number == 10)
		*str = "Jean_Jacques_Rousseau";
	else if (number == 11)
		*str = "David_Hume";
	else if (number == 12)
		*str = "Immanuel_Kant";
	else if (number == 13)
		*str = "Leibniz";
	else if (number == 14)
		*str = "John_Locke";
	else if (number == 15)
		*str = "John_Rawls";
	else if (number == 16)
		*str = "Robert_Nozick";
	else if (number == 17)
		*str = "Slavoj_Zizek";
	else if (number == 18)
		*str = "Foucault";
	else
		convert_names_3(number, str);
}

void	convert_names_1(int number, char **str)
{
	if (number == 1)
		*str = "Kong_Qiu";
	else if (number == 2)
		*str = "Anaximander";
	else if (number == 3)
		*str = "Xenofanes";
	else if (number == 4)
		*str = "Pythagoras";
	else if (number == 5)
		*str = "Socrates";
	else if (number == 6)
		*str = "Plato";
	else if (number == 7)
		*str = "Aristotle";
	else if (number == 8)
		*str = "Miyamoto_Musashi";
	else if (number == 9)
		*str = "Rene_Descartes";
	else
		convert_names_2(number, str);
}
