#include <unistd.h>

static inline int	int_len(int n)
{
	int len;

	len = 0;
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static inline
	void	lotoa(int n, char *buf, int len)
{
	if(n > 9)
	{
		lotoa(n / 10, buf, len - 1);
		buf[len] = n % 10 - 0;
	}
}

void	write_to_buf(char *buf, size_t *len, int id, long time)
{
}
