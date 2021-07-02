/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspinnet <mspinnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 11:34:25 by mspinnet          #+#    #+#             */
/*   Updated: 2020/12/11 11:08:23 by mspinnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*s2;
	unsigned int	i;
	size_t			l;

	i = 0;
	if (s == NULL)
		return (NULL);
	l = ft_strlen(s);
	s2 = (char*)malloc(sizeof(char) * len + 1);
	if (NULL == s2)
		return (NULL);
	while (len > 0 && start <= l)
	{
		s2[i] = s[start];
		i++;
		start++;
		len--;
	}
	s2[i] = '\0';
	return (s2);
}
