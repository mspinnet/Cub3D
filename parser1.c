/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspinnet <mspinnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 16:39:11 by mspinnet          #+#    #+#             */
/*   Updated: 2021/01/23 12:49:30 by mspinnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_flags	make_value_r(char **map, t_flags flag, int i, int j)
{
	j++;
	map[i][j] == 32 ? j = is_space(map, j, i) : flag.err++;
	flag.r_x == -1 ? flag.r_x = ft_atoi(&map[i][j]) : flag.err++;
	while (ft_isdigit(map[i][j]) == 1)
		j++;
	j = is_space(map, j, i);
	flag.r_y == -1 ? flag.r_y = ft_atoi(&map[i][j]) : flag.err++;
	while (ft_isdigit(map[i][j]) == 1)
		j++;
	j = is_space(map, j, i);
	map[i][j] != '\0' ? flag.err++ : 0;
	flag.j++;
	flag.r_x == 0 ? flag.err++ : 0;
	flag.r_y == 0 ? flag.err++ : 0;
	flag.r_x < 100 ? flag.r_x = 100 : 0;
	flag.r_y < 100 ? flag.r_y = 100 : 0;
	flag.r_x > 2560 ? flag.r_x = 2560 : 0;
	flag.r_y > 1440 ? flag.r_y = 1440 : 0;
	return (flag);
}

t_flags	make_value_text(char **m, int j, int i, t_flags f)
{
	char	*str;
	int		c;
	int		k;

	c = j;
	j++;
	m[i][j] == 'O' || m[i][j] == 'E' || m[i][j] == 'A' ? j++ : 0;
	m[i][j] == 32 ? j = is_space(m, j, i) : f.err++;
	k = j;
	while (m[i][j] != 32 && m[i][j] != '\0')
		j++;
	str = ft_substr(m[i], k, j - k);
	str == NULL ? write(1, "Error malloc!\n", 14) : 0;
	str == NULL ? exit(0) : 0;
	j = is_space(m, j, i);
	m[i][j] != '\0' ? f.err++ : 0;
	m[i][c] == 'N' && f.no == NULL ? f.no = str : 0;
	m[i][c] == 'W' && f.we == NULL ? f.we = str : 0;
	m[i][c] == 'E' && f.ea == NULL ? f.ea = str : 0;
	m[i][c] == 'S' && f.so == NULL && m[i][c + 1] == 'O' ? f.so = str : 0;
	m[i][c] == 'S' && f.s == NULL && m[i][c + 1] == ' ' ? f.s = str : 0;
	f.j++;
	return (f);
}

t_flags	make_value_f(char **map, int j, int i, t_flags flag)
{
	int k;

	k = 0;
	j++;
	map[i][j] == 32 ? j = is_space(map, j, i) : flag.err++;
	while (k < 3)
	{
		if (ft_isdigit(map[i][j]) == 1)
			flag.f[k] == -1 ? flag.f[k] = ft_atoi(&map[i][j]) : flag.err++;
		else
			flag.err++;
		while (ft_isdigit(map[i][j]) == 1)
			j++;
		j = is_space(map, j, i);
		map[i][j] == ',' || map[i][j] == '\0' ? j++ : flag.err++;
		j = is_space(map, j, i);
		k++;
	}
	if (flag.f[0] > 255 || flag.f[1] > 255 || flag.f[2] > 255)
		flag.err++;
	flag.j++;
	return (flag);
}

t_flags	make_value_c(char **map, int j, int i, t_flags flag)
{
	int k;

	k = 0;
	j++;
	map[i][j] == 32 ? j = is_space(map, j, i) : flag.err++;
	while (k < 3)
	{
		if (ft_isdigit(map[i][j]) == 1)
			flag.c[k] == -1 ? flag.c[k] = ft_atoi(&map[i][j]) : flag.err++;
		else
			flag.err++;
		while (ft_isdigit(map[i][j]) == 1)
			j++;
		j = is_space(map, j, i);
		map[i][j] == ',' || map[i][j] == '\0' ? j++ : flag.err++;
		j = is_space(map, j, i);
		k++;
	}
	if (flag.c[0] > 255 || flag.c[1] > 255 || flag.c[2] > 255)
		flag.err++;
	flag.j++;
	return (flag);
}

t_flags	make_valueall(char **m, t_flags flag)
{
	int i;
	int j;

	i = -1;
	while (m[++i])
	{
		j = is_space(m, 0, i);
		if (m[i][j] != 'R' && m[i][j] != 'N' && m[i][j] != 'S' &&
		m[i][j] != 'W' && m[i][j] != 'F' && m[i][j] != 'C' &&
		m[i][j] != 'E' && m[i][j] != '1' && m[i][j] != '\0')
			flag.err++;
		if (m[i][j] == 'R')
			flag = make_value_r(m, flag, i, j);
		if (m[i][j] == 'S' || m[i][j] == 'N' || m[i][j] == 'E'
		|| m[i][j] == 'W')
			flag = make_value_text(m, j, i, flag);
		if (m[i][j] == 'F')
			flag = make_value_f(m, j, i, flag);
		if (m[i][j] == 'C')
			flag = make_value_c(m, j, i, flag);
	}
	return (flag);
}
