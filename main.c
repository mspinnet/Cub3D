/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspinnet <mspinnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 12:45:30 by mspinnet          #+#    #+#             */
/*   Updated: 2021/01/23 12:50:10 by mspinnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	make_list(t_all *all, t_arg *arg, char *str)
{
	arg->fd = open(str, O_RDONLY);
	if (arg->fd == -1)
	{
		write(1, "Error map!\n", 11);
		exit(0);
	}
	while ((arg->gnl = get_next_line(arg->fd, &arg->line)))
	{
		if (arg->gnl == -1)
		{
			write(1, "Error\n", 7);
			exit(0);
		}
		ft_lstadd_back(&all->head, ft_lstnew(arg->line));
	}
	ft_lstadd_back(&all->head, ft_lstnew(arg->line));
	close(arg->fd);
}

void	formain(t_all *all, t_arg *arg, char *str)
{
	arg->str = make_all(str);
	arg->j = delitel(arg->str);
	arg->str2 = ft_substr(arg->str, arg->j, ft_strlen(arg->str) - arg->j);
	if (arg->str == NULL || arg->str2 == NULL)
	{
		write(1, "Error malloc!\n", 14);
		exit(0);
	}
	make_list(all, arg, str);
	all->map = make_map(&all->head, ft_lstsize(all->head));
	all->flag = make_flags();
	all->flag = make_valueall(all->map, all->flag);
	all->flag = errors(all->flag);
	all->map = map_valid(arg->str2, all->flag);
	ray_init(all);
	mlx_start(all);
}

void	formain2(t_all *all, t_arg *arg, char *str)
{
	arg->str = make_all(str);
	arg->j = delitel(arg->str);
	arg->str2 = ft_substr(arg->str, arg->j, ft_strlen(arg->str) - arg->j);
	if (arg->str == NULL || arg->str2 == NULL)
	{
		write(1, "Error malloc!\n", 14);
		exit(0);
	}
	make_list(all, arg, str);
	all->map = make_map(&all->head, ft_lstsize(all->head));
	all->flag = make_flags();
	all->flag = make_valueall(all->map, all->flag);
	all->flag = errors(all->flag);
	all->map = map_valid(arg->str2, all->flag);
	ray_init(all);
	mlx_start_print(all);
	exit(0);
}

int		main(int argc, char **argv)
{
	t_all	all;
	t_arg	arg;

	if (argc == 2)
		formain(&all, &arg, argv[1]);
	if (argc == 3)
	{
		if (ft_memcmp("--save", argv[2], 7) == 0)
			formain2(&all, &arg, argv[1]);
		else
		{
			write(1, "Error argument!\n", 16);
			exit(0);
		}
	}
	if (argc < 2 || argc > 3)
	{
		write(1, "Error argument!\n", 16);
		exit(0);
	}
	return (0);
}
