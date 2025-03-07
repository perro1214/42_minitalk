#include "minitalk.h"

static void ft_send(int pid,char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '1')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(80);
	}
}

static char *ft_convert(char *s,size_t i,size_t j)
{
	char *result;
	int c;
	int bytes;

	i = ft_strlen(s);
	result = ft_calloc(i * 8 + 1, sizeof(char));
	if(result == NULL)
		return (NULL);
	while(i + 1 != 0)
	{
		c = s[i - 1];
		bytes = 8;
		while(bytes > 0)
		{
			if(c % 2 == 1)
				result[ft_strlen(s) * 8 - j - 1] = '1';
			else
				result[ft_strlen(s) * 8 - j - 1] = '0';
			c /= 2;
			j++;
			bytes--;
		}
		i--;
	}
	return (result);
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*bits;

	if (argc != 3)
	{
		ft_printf("wrong number of arguments\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	bits = ft_convert(argv[2], 0, 0);
	if (bits == NULL)
	{
		ft_printf("allocation went wrong\n");
		return (0);
	}
	ft_send(pid, bits);
	free(bits);
}
