/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 17:14:57 by avieira-          #+#    #+#             */
/*   Updated: 2025/09/28 18:40:19 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void    error_message_get(int error_code, char **error_message)
{
    *error_message = NULL;
    if (error_code == 1)
        *error_message = MSG_USE;
}

void    error_exit(int error_code)
{
    char    *error_message;

    error_message_get(error_code, &error_message);
    ft_putstr_fd(error_message, 2);
    exit(error_code);
}
