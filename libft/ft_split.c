/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspinnet <mspinnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:18:15 by mspinnet          #+#    #+#             */
/*   Updated: 2020/12/08 14:21:32 by mspinnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	char	**ar;
	size_t	i;
	size_t	j;
	size_t	k;

	i = -1;
	k = 0;
	if (s == 0)
		return (NULL);
	while (s[++i])
		if ((s[i] == c && (s[i + 1] != c && s[i + 1] != '\0')) ||
		(s[i] != c && s[i + 1] == '\0'))
			k++;
	if (!(ar = (char**)malloc(sizeof(char*) * (k + 2))))
		return (NULL);
	i = -1;
	k = 0;
	j = 0;
	while (s[++i])
		if (s[i] == c && s[i + 1] != c)
			k = i + 1;
		else if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			ar[j++] = ft_substr(s, k, i - k + 1);
	ar[j] = NULL;
	return (ar);
}
