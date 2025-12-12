/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 02:32:32 by avieira-          #+#    #+#             */
/*   Updated: 2025/12/12 02:32:33 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static
	void	itoa_write(long n, char *buf, int len)
{
	if (n > 9)
		itoa_write(n / 10, buf, len - 1);
	buf[len] = n % 10 + '0';
}

void	ft_itoa(int n, char *buf)
{
	int	len;

	len = 0;
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	len++;
	itoa_write(n, buf, len - 1);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_is_digit(char c)
{
	if (c < '0' || c > '9')
		return (-1);
	return (0);
}

long	ft_atol(char *nbr)
{
	int		i;
	long	n;

	i = 0;
	n = 0;
	while (nbr[i])
	{
		n = n * 10 + nbr[i] - '0';
		i++;
	}
	return (n);
}
