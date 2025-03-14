/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhayato <hhayato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:04:15 by hhayato           #+#    #+#             */
/*   Updated: 2025/03/14 12:04:26 by hhayato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_confirm(int sig)
{
	static unsigned char	current_char;
	static int				bit_index;

	current_char |= (sig == SIGUSR1);
	bit_index++;
	if (bit_index == 8)
	{
		if (current_char == '\0')
			ft_putchar_fd('\n', 1);
		else
			ft_putchar_fd(current_char, 1);
		bit_index = 0;
		current_char = 0;
	}
	else
		current_char <<= 1;
}

int	main(void)
{
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	signal(SIGUSR1, ft_confirm);
	signal(SIGUSR2, ft_confirm);
	while (1 == 1)
	{
		pause();
	}
	return (0);
}
