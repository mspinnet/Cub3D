/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspinnet <mspinnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 12:17:29 by mspinnet          #+#    #+#             */
/*   Updated: 2021/01/23 12:49:27 by mspinnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*make_all(char *str)
{
	int		fd;
	char	buf;
	char	*res;
	int		i;

	i = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Error map!\n", 11);
		exit(0);
	}
	while (read(fd, &buf, 1))
		i++;
	close(fd);
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (res == NULL)
		return (NULL);
	fd = open(str, O_RDONLY);
	i = 0;
	while (read(fd, &buf, 1))
		res[i++] = buf;
	close(fd);
	return (res);
}

int		map_count1(char *str, int i, int count)
{
	while (str[++i])
	{
		if (i == 0)
			while (str[++i] != '\n' && str[i])
				if (str[i] != ' ' && str[i] != '1')
					count++;
		if (str[i] == 'N' || str[i] == 'W' || str[i] == 'E' || str[i] == 'S')
			count++;
		if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != 'N'
		&& str[i] != 'W' && str[i] != 'E' && str[i] != 'S' && str[i] != ' '
		&& str[i] != '\n')
			count++;
		str[i] == ' ' && (str[i - 1] == '0' || str[i + 1] == '0') ? count++ : 0;
		if (str[i] == '\n' && ((str[i - 1] != '1' && str[i - 1] != ' ') ||
		(str[i + 1] != '1' && str[i + 1] != ' ' && str[i + 1] != '\0')))
			count++;
		if (str[i] == ' ')
		{
			while (str[i] == ' ' && str[i])
				i++;
			if (str[i] != '1' && str[i] != '\n' && str[i] != '\0')
				count++;
		}
	}
	return (count);
}

int		map_count(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = map_count1(str, -1, 0);
	while (str[i])
		i++;
	if (str[i - 1] == '\n')
		i--;
	while (str[--i] != '\n')
		if (str[i] != ' ' && str[i] != '1')
			count++;
	return (count);
}

int		map_valid2(char **m)
{
	int	i;
	int	j;

	i = 0;
	while (m[++i])
	{
		j = -1;
		while (m[i][++j])
		{
			if (((m[i][j] == '0' || m[i][j] == '2') &&
			(m[i + 1][j + 1] == '\0' || m[i + 1][j + 1] == ' ')) ||
			((m[i][j] == '0' || m[i][j] == '2') && (m[i - 1]
			[j + 1] == '\0' || m[i - 1][j + 1] == ' ')) ||
			((m[i][j] == '0' || m[i][j] == '2') && (m[i + 1][j - 1] == '\0' ||
			m[i + 1][j - 1] == ' ')) ||
			((m[i][j] == '0' || m[i][j] == '2') && (m[i - 1][j - 1] == '\0' ||
			m[i - 1][j - 1] == ' ')) || ((m[i][j] == '0' || m[i][j] == '2') &&
			(m[i + 1][j] == '\0' || m[i + 1][j] == ' ')) || ((m[i][j] == '0'
			|| m[i][j] == '2') && (m[i - 1][j] == '\0' || m[i - 1][j] == ' ')))
				return (1);
		}
	}
	return (0);
}

char	**map_valid(char *str2, t_flags flag)
{
	int		count;
	char	**map;

	map = ft_split((const char *)str2, '\n');
	if (map == NULL)
	{
		write(1, "Error malloc!\n", 14);
		exit(0);
	}
	count = map_count(str2);
	if (count != 1 || flag.j != 8 || flag.err != 0)
	{
		write(1, "Error map!\n", 11);
		exit(0);
	}
	if (map_valid2(map) != 0)
	{
		write(1, "Error map!\n", 11);
		exit(0);
	}
	return (map);
}
