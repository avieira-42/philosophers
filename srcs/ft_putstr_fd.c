/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 21:36:04 by jesusoncrac       #+#    #+#             */
/*   Updated: 2025/09/28 18:43:18 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd != -1)
		write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s && fd != -1)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}
