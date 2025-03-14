/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhayato <hhayato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:03:47 by hhayato           #+#    #+#             */
/*   Updated: 2025/03/14 12:04:30 by hhayato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_send_char(pid_t pid, char c)
{
	int	bit;

	bit = 7;
	while (bit != -1)
	{
		if (c & (1 << bit))
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		bit--;
		usleep(1000);
	}
	usleep(1000);
}

static void	ft_send_str(pid_t pid, char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_send_char(pid, s[i]);
		i++;
		usleep(1000);
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*str;

	if (argc != 3)
	{
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	str = argv[2];
	ft_send_str(pid, str);
}
