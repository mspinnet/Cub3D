/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspinnet <mspinnet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 14:25:41 by mspinnet          #+#    #+#             */
/*   Updated: 2020/11/02 21:06:20 by mspinnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	cc;
	unsigned char	*str;

	i = 0;
	str = b;
	cc = (unsigned char)c;
	while (i < len)
	{
		str[i] = cc;
		i++;
	}
	return (b);
}
