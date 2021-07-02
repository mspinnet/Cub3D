/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspinnet <mspinnet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:20:20 by mspinnet          #+#    #+#             */
/*   Updated: 2020/11/04 11:52:56 by mspinnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char*)malloc(count * size);
	if (NULL == str)
		return (NULL);
	while (i < count * size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
