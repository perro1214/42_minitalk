/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_fd_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhayato <hhayato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:34:40 by hhayato           #+#    #+#             */
/*   Updated: 2024/12/18 16:36:43 by hhayato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd_int(char *c, int fd)
{
	int	res;

	res = 0;
	if (c == NULL)
	{
		res += write(fd, "(null)", 6);
		return (res);
	}
	while (*c != '\0')
	{
		res += write(fd, c, 1);
		c++;
	}
	return (res);
}

int	ft_putchar_fd_int(char c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_putnbr_fd_int(int n, int fd)
{
	int	res;

	res = 0;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			return (ft_putstr_fd_int("-2147483648", fd));
		}
		res += ft_putstr_fd_int("-", fd);
		n = -n;
	}
	if (n / 10 != 0)
	{
		res += ft_putnbr_fd_int(n / 10, fd);
		res += ft_putnbr_fd_int(n % 10, fd);
	}
	else
	{
		res += ft_putchar_fd_int('0' + n, fd);
	}
	return (res);
}

int	ft_putabsnbr_fd_int(unsigned int n, int fd)
{
	int	res;

	res = 0;
	if (n / 10 != 0)
	{
		res += ft_putabsnbr_fd_int(n / 10, fd);
		res += ft_putabsnbr_fd_int(n % 10, fd);
	}
	else
	{
		res += ft_putchar_fd_int('0' + n, fd);
	}
	return (res);
}
