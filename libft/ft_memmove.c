/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspinnet <mspinnet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:56:44 by mspinnet          #+#    #+#             */
/*   Updated: 2020/10/30 16:56:23 by mspinnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*str1;
	const char		*str2;

	i = 0;
	str1 = dst;
	str2 = src;
	if (dst == '\0' && src == '\0')
		return (NULL);
	if (src > dst)
		while (i < len)
		{
			str1[i] = str2[i];
			i++;
		}
	else
		while (len > 0)
		{
			str1[len - 1] = str2[len - 1];
			len--;
		}
	return (dst);
}
