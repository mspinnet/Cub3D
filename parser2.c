/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspinnet <mspinnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 16:04:45 by mspinnet          #+#    #+#             */
/*   Updated: 2021/01/23 12:49:33 by mspinnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_flags	errors(t_flags f)
{
	int fd;

	if (f.s == NULL || f.r_y == -1 || f.r_x == -1 || f.f[0] == -1 ||
	f.f[1] == -1 || f.f[2] == -1 || f.c[0] == -1 || f.c[1] == -1 || f.c[2] == -1
	|| f.no == NULL || f.so == NULL || f.we == NULL || f.ea == NULL)
		f.err++;
	fd = open(f.s, O_RDONLY);
	fd == -1 ? f.err++ : 0;
	close(fd);
	fd = open(f.so, O_RDONLY);
	fd == -1 ? f.err++ : 0;
	close(fd);
	fd = open(f.no, O_RDONLY);
	fd == -1 ? f.err++ : 0;
	close(fd);
	fd = open(f.we, O_RDONLY);
	fd == -1 ? f.err++ : 0;
	close(fd);
	fd = open(f.ea, O_RDONLY);
	fd == -1 ? f.err++ : 0;
	close(fd);
	return (f);
}

int		is_space(char **map, int j, int i)
{
	if (map[i][j] == 32)
		while (map[i][j] == 32)
			j++;
	return (j);
}

char	**make_map(t_list **head, int size)
{
	char	**map;
	int		i;
	t_list	*tmp;

	i = -1;
	map = ft_calloc(size + 1, sizeof(char *));
	if (map == NULL)
	{
		write(1, "Error malloc!\n", 14);
		exit(0);
	}
	tmp = *head;
	while (tmp)
	{
		map[++i] = tmp->content;
		tmp = tmp->next;
	}
	return (map);
}

t_flags	make_flags(void)
{
	t_flags flag;

	flag.s = NULL;
	flag.r_y = -1;
	flag.r_x = -1;
	flag.f[0] = -1;
	flag.f[1] = -1;
	flag.f[2] = -1;
	flag.c[0] = -1;
	flag.c[1] = -1;
	flag.c[2] = -1;
	flag.no = NULL;
	flag.so = NULL;
	flag.we = NULL;
	flag.ea = NULL;
	flag.j = 0;
	flag.err = 0;
	return (flag);
}

int		delitel(char *str)
{
	int i;
	int	j;

	i = 0;
	while (str[i])
	{
		while (str[i] != '\n' && str[i])
			i++;
		if (str[i] == '\n' && str[i + 1] != ' ' && str[i + 1] != '1')
			i++;
		if (str[i] == '\n' && (str[i + 1] == ' ' || str[i + 1] == '1'))
		{
			i++;
			j = i;
			while (str[i] == ' ' && str[i])
				i++;
			if (str[i] != '1')
				i++;
			else
				break ;
		}
	}
	return (j);
}
