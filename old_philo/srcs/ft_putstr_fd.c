#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	if (fd != -1)
		write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	while (s && *s && fd != -1)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}
