#include <unistd.h>

static inline
	int	long_len(long n)
{
	int len;

	len = 0;
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len + 1);
}

static inline
	void	write_long_to_buf(long n, char *buf, int len)
{
	if(n > 9)
		write_long_to_buf(n / 10, buf, len - 1);
	buf[len] = n % 10 + '0';
}

static inline
	void	lotoa(long n, char *buf, int *len)
{
	*len = long_len(n);
	write_long_to_buf(n, buf, *len - 1);
}

void	state_write(long time, char *id, char *state)
{
	int	i;
	int	msg_len;
	char msg[100];

	lotoa(time, msg, &msg_len);
	i = 0;
	msg[msg_len++] = ' ';
	while (id[i])
		msg[msg_len++] = id[i++];
	i = 0;
	msg[msg_len++] = ' ';
	while (state[i])
		msg[msg_len++] = state[i++];
	write(1, msg, msg_len);
}
