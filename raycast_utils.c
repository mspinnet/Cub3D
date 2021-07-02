/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspinnet <mspinnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 12:08:34 by mspinnet          #+#    #+#             */
/*   Updated: 2021/01/23 12:49:40 by mspinnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	raycast_init(t_all *all, int x)
{
	all->ray.hit = 0;
	all->ray.cam_x = 2 * x / (double)all->flag.r_x - 1;
	all->ray.ray_dir_x = all->ray.dir_x + all->ray.plane_x * all->ray.cam_x;
	all->ray.ray_dir_y = all->ray.dir_y + all->ray.plane_y * all->ray.cam_x;
	all->ray.map_x = (int)all->ray.pos_x;
	all->ray.map_y = (int)all->ray.pos_y;
	all->ray.delta_dist_x = fabs(1 / all->ray.ray_dir_x);
	all->ray.delta_dist_y = fabs(1 / all->ray.ray_dir_y);
}

void	raycast_step(t_all *all)
{
	if (all->ray.ray_dir_x < 0)
	{
		all->ray.step_x = -1;
		all->ray.side_dist_x = (all->ray.pos_x - all->ray.map_x) *
			all->ray.delta_dist_x;
	}
	else
	{
		all->ray.step_x = 1;
		all->ray.side_dist_x = (all->ray.map_x + 1.0 - all->ray.pos_x) *
			all->ray.delta_dist_x;
	}
	if (all->ray.ray_dir_y < 0)
	{
		all->ray.step_y = -1;
		all->ray.side_dist_y = (all->ray.pos_y - all->ray.map_y) *
			all->ray.delta_dist_y;
	}
	else
	{
		all->ray.step_y = 1;
		all->ray.side_dist_y = (all->ray.map_y + 1.0 - all->ray.pos_y) *
			all->ray.delta_dist_y;
	}
}

void	raycast_hit(t_all *all)
{
	while (all->ray.hit == 0)
	{
		if (all->ray.side_dist_x < all->ray.side_dist_y)
		{
			all->ray.side_dist_x += all->ray.delta_dist_x;
			all->ray.map_x += all->ray.step_x;
			all->ray.side = 0;
		}
		else
		{
			all->ray.side_dist_y += all->ray.delta_dist_y;
			all->ray.map_y += all->ray.step_y;
			all->ray.side = 1;
		}
		if (all->map[all->ray.map_x][all->ray.map_y] == '1')
			all->ray.hit = 1;
	}
	if (all->ray.side == 0)
		all->ray.pwd = (all->ray.map_x - all->ray.pos_x +
		(1 - all->ray.step_x) / 2) / all->ray.ray_dir_x;
	else
		all->ray.pwd = (all->ray.map_y - all->ray.pos_y +
		(1 - all->ray.step_y) / 2) / all->ray.ray_dir_y;
}

void	raycast_tex_init(t_all *all)
{
	all->ray.line_h = (int)(all->flag.r_y / all->ray.pwd);
	all->ray.d_start = -all->ray.line_h / 2 + all->flag.r_y / 2;
	if (all->ray.d_start < 0)
		all->ray.d_start = 0;
	all->ray.d_end = all->ray.line_h / 2 + all->flag.r_y / 2;
	if (all->ray.d_end >= all->flag.r_y)
		all->ray.d_end = all->flag.r_y - 1;
	if (all->ray.side == 0)
		all->tex.wallx = all->ray.pos_y + all->ray.pwd * all->ray.ray_dir_y;
	else
		all->tex.wallx = all->ray.pos_x + all->ray.pwd * all->ray.ray_dir_x;
	all->tex.wallx -= floor(all->tex.wallx);
	all->tex.tex_x = (int)(all->tex.wallx * (double)all->tex.tex_width);
	if (all->ray.side == 0 && all->ray.ray_dir_x > 0)
		all->tex.tex_x = all->tex.tex_width - all->tex.tex_x - 1;
	if (all->ray.side == 1 && all->ray.ray_dir_y < 0)
		all->tex.tex_x = all->tex.tex_width - all->tex.tex_x - 1;
	all->tex.step = 1.0 * all->tex.tex_height / all->ray.line_h;
	all->tex.tex_pos = (all->ray.d_start - (all->flag.r_y / 2) +
		(all->ray.line_h / 2)) * all->tex.step;
}

void	raycast_tex(t_all *all, int x)
{
	int		y;

	y = all->ray.d_start;
	while (y < all->ray.d_end)
	{
		all->tex.tex_y = (int)all->tex.tex_pos;
		all->tex.tex_pos += all->tex.step;
		pixel_put(&all->win, x, y++, get_color(all));
	}
}
