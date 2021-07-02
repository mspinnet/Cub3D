/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspinnet <mspinnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 12:06:09 by mspinnet          #+#    #+#             */
/*   Updated: 2021/01/19 20:04:04 by mspinnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_player_3d(t_all *all)
{
	t_point pos;

	ft_bzero(&pos, sizeof(t_point));
	while (all->map[pos.y])
	{
		pos.x = 0;
		while (all->map[pos.y][pos.x])
		{
			if (ft_strchr("N", all->map[pos.y][pos.x]))
				init_if_n(all, pos);
			if (ft_strchr("S", all->map[pos.y][pos.x]))
				init_if_s(all, pos);
			if (ft_strchr("W", all->map[pos.y][pos.x]))
				init_if_w(all, pos);
			if (ft_strchr("E", all->map[pos.y][pos.x]))
				init_if_e(all, pos);
			if (ft_strchr("2", all->map[pos.y][pos.x]))
				all->sprite.number++;
			pos.x++;
		}
		pos.y++;
	}
}

void	init_if_w(t_all *all, t_point pos)
{
	all->ray.pos_x = pos.y + 0.5;
	all->ray.pos_y = pos.x + 0.5;
	all->ray.dir_x = 0;
	all->ray.dir_y = -1;
	all->ray.plane_x = -0.66;
	all->ray.plane_y = 0;
}

void	init_if_n(t_all *all, t_point pos)
{
	all->ray.pos_x = pos.y + 0.5;
	all->ray.pos_y = pos.x + 0.5;
	all->ray.dir_x = -1;
	all->ray.dir_y = 0;
	all->ray.plane_x = 0;
	all->ray.plane_y = 0.66;
}

void	init_if_s(t_all *all, t_point pos)
{
	all->ray.pos_x = pos.y + 0.5;
	all->ray.pos_y = pos.x + 0.5;
	all->ray.dir_x = 1;
	all->ray.dir_y = 0;
	all->ray.plane_x = 0;
	all->ray.plane_y = -0.66;
}

void	init_if_e(t_all *all, t_point pos)
{
	all->ray.pos_x = pos.y + 0.5;
	all->ray.pos_y = pos.x + 0.5;
	all->ray.dir_x = 0;
	all->ray.dir_y = 1;
	all->ray.plane_x = 0.66;
	all->ray.plane_y = 0;
}
