/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspinnet <mspinnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 12:15:08 by mspinnet          #+#    #+#             */
/*   Updated: 2021/01/21 22:08:30 by mspinnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		move_flag_check(t_all *all)
{
	if (all->ray.key_flag_s == 1)
		key_press_s(all);
	if (all->ray.key_flag_w == 1)
		key_press_w(all);
	if (all->ray.key_flag_a == 1)
		key_press_a(all);
	if (all->ray.key_flag_d == 1)
		key_press_d(all);
	if (all->ray.key_flag_left == 1)
		key_press_left(all);
	if (all->ray.key_flag_right == 1)
		key_press_right(all);
	return (0);
}

int		key_flags(int keycode, t_all *all)
{
	if (keycode == 13)
		all->ray.key_flag_w = 1;
	if (keycode == 1)
		all->ray.key_flag_s = 1;
	if (keycode == 0)
		all->ray.key_flag_a = 1;
	if (keycode == 2)
		all->ray.key_flag_d = 1;
	if (keycode == 123)
		all->ray.key_flag_left = 1;
	if (keycode == 124)
		all->ray.key_flag_right = 1;
	if (keycode == 53)
		exit(0);
	return (0);
}

int		key_flags2(int keycode, t_all *all)
{
	if (keycode == 13)
		all->ray.key_flag_w = 0;
	if (keycode == 1)
		all->ray.key_flag_s = 0;
	if (keycode == 0)
		all->ray.key_flag_a = 0;
	if (keycode == 2)
		all->ray.key_flag_d = 0;
	if (keycode == 123)
		all->ray.key_flag_left = 0;
	if (keycode == 124)
		all->ray.key_flag_right = 0;
	return (0);
}

int		key_press2(int x, int y, t_all *all)
{
	int		x2;
	int		y2;

	y = 0;
	x = 1180;
	mlx_mouse_hide();
	mlx_mouse_get_pos(all->win.win, &x2, &y2);
	mlx_mouse_move(all->win.win, 1180, 0);
	if (x2 - x < 0)
		mouse_move_left(all, x, x2);
	if (x2 - x > 0)
		mouse_move_right(all, x, x2);
	raycast(all);
	return (0);
}

void	key_press_right(t_all *all)
{
	all->ray.old_dir_x = all->ray.dir_x;
	all->ray.dir_x = all->ray.dir_x * cos(-0.045) -
		all->ray.dir_y * sin(-0.045);
	all->ray.dir_y = all->ray.old_dir_x * sin(-0.045) +
		all->ray.dir_y * cos(-0.045);
	all->ray.old_plane_x = all->ray.plane_x;
	all->ray.plane_x = all->ray.plane_x * cos(-0.045) -
		all->ray.plane_y * sin(-0.045);
	all->ray.plane_y = all->ray.old_plane_x * sin(-0.045) +
		all->ray.plane_y * cos(-0.045);
}
