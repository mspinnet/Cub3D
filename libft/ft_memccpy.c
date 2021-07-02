/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspinnet <mspinnet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:25:47 by mspinnet          #+#    #+#             */
/*   Updated: 2020/10/31 18:12:47 by mspinnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		if (*((unsigned char*)src + i) != (unsigned char)c)
		{
			*((unsigned char*)dst + i) = *((unsigned char*)src + i);
			i++;
		}
		else
		{
			*((unsigned char*)dst + i) = (unsigned char)c;
			return (&dst[i + 1]);
		}
	}
	return (NULL);
}
