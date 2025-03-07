/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhayato <hhayato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:33:35 by hhayato           #+#    #+#             */
/*   Updated: 2024/12/18 16:36:21 by hhayato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../srcs/libft/libft.h"
# include <ctype.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *fmt, ...);
int	ft_putstr_fd_int(char *c, int fd);
int	ft_putchar_fd_int(char c, int fd);
int	ft_putnbr_fd_int(int n, int fd);
int	ft_putabsnbr_fd_int(unsigned int n, int fd);
char	*ft_hextoa(unsigned int n,char * tr_list);
char	*ft_pointer_hextoa(size_t n,char * tr_list);
char *tr_hex(size_t number);
char *tr_heX(size_t number);
char *tr_pointer(size_t number);
int printchar(va_list ap);
int printstr(va_list ap);
int printint(va_list ap);
int printpointer(va_list ap);
int printabsint(va_list ap);
int printhex(va_list ap);
int printheX(va_list ap);


#endif