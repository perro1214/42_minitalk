/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhayato <hhayato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:50:33 by hhayato           #+#    #+#             */
/*   Updated: 2024/10/30 15:59:06 by hhayato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	int	ans;

	ans = ((('0' <= c) && (c <= '9'))
			|| (('a' <= c) && (c <= 'z'))
			|| (('A' <= c) && (c <= 'Z')));
	return (ans);
}

// int main(void){
//     if(ft_isalnum('a')==1){
//         write(1,"Yes1",4);
//     }
//     if(ft_isalnum('A')==1){
//         write(1,"Yes2",4);
//     }
//     if(ft_isalnum('1')==1){
//         write(1,"Yes3",4);
//     }
//     if(ft_isalnum(1)==1){
//         write(1,"Yes4",4);
//     }
// }
