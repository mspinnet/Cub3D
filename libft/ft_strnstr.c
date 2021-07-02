/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspinnet <mspinnet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 13:08:08 by mspinnet          #+#    #+#             */
/*   Updated: 2020/11/06 11:22:56 by mspinnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *stack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char*)stack);
	while (stack[i] && needle[j] && i < len)
	{
		if (stack[i] != needle[j])
			i++;
		else
		{
			if (ft_strncmp(&stack[i], needle, ft_strlen(needle)) != 0)
				i++;
			else if (ft_strncmp(&stack[i], needle, ft_strlen(needle)) == 0 &&
					i + ft_strlen(needle) <= len)
				return ((char*)&stack[i]);
			else
				return (NULL);
		}
	}
	return (NULL);
}
