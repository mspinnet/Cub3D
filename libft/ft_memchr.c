/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspinnet <mspinnet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 20:35:23 by mspinnet          #+#    #+#             */
/*   Updated: 2020/11/02 21:07:18 by mspinnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t					i;
	const unsigned char		*str;
	unsigned char			cc;

	i = 0;
	str = s;
	cc = (unsigned char)c;
	while (i < n)
	{
		if (str[i] != cc)
			i++;
		else
			return ((void*)s + i);
	}
	return (NULL);
}
