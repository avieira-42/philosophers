#include "../include/philo.h"

void    error_message_get(int error_code, char **error_message)
{
    *error_message = NULL;
    if (error_code == 1)
        *error_message = MSG_USE;
	if (error_code == 2)
		*error_message = MSG_ALLOC_ERR;
}

void    error_exit(t_feast *feast, int error_code)
{
    char    *error_message;

    error_message_get(error_code, &error_message);
    ft_putstr_fd(error_message, 2);
    exit(error_code);
}
