/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspinnet <mspinnet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 12:40:54 by mspinnet          #+#    #+#             */
/*   Updated: 2020/11/06 10:57:08 by mspinnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (((unsigned char)s1[i] - (unsigned char)s2[i]) > 0)
			return (1);
		if (((unsigned char)s1[i] - (unsigned char)s2[i]) < 0)
			return (-1);
		i++;
	}
	return (0);
}
