/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_move_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspinnet <mspinnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 22:01:17 by mspinnet          #+#    #+#             */
/*   Updated: 2021/01/21 22:08:23 by mspinnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	mouse_move_right(t_all *all, int x, int x2)
{
	all->ray.old_dir_x = all->ray.dir_x;
	all->ray.dir_x = all->ray.dir_x * cos(-0.005 * abs(x2 - x)) -
		all->ray.dir_y * sin(-0.005 * abs(x2 - x));
	all->ray.dir_y = all->ray.old_dir_x * sin(-0.005 * abs(x2 - x)) +
		all->ray.dir_y * cos(-0.005 * abs(x2 - x));
	all->ray.old_plane_x = all->ray.plane_x;
	all->ray.plane_x = all->ray.plane_x * cos(-0.005 * abs(x2 - x)) -
		all->ray.plane_y * sin(-0.005 * abs(x2 - x));
	all->ray.plane_y = all->ray.old_plane_x * sin(-0.005 * abs(x2 - x)) +
		all->ray.plane_y * cos(-0.005 * abs(x2 - x));
}

void	mouse_move_left(t_all *all, int x, int x2)
{
	all->ray.old_dir_x = all->ray.dir_x;
	all->ray.dir_x = all->ray.dir_x * cos(0.005 * abs(x2 - x)) -
		all->ray.dir_y * sin(0.005 * abs(x2 - x));
	all->ray.dir_y = all->ray.old_dir_x * sin(0.005 * abs(x2 - x)) +
		all->ray.dir_y * cos(0.005 * abs(x2 - x));
	all->ray.old_plane_x = all->ray.plane_x;
	all->ray.plane_x = all->ray.plane_x * cos(0.005 * abs(x2 - x)) -
		all->ray.plane_y * sin(0.005 * abs(x2 - x));
	all->ray.plane_y = all->ray.old_plane_x * sin(0.005 * abs(x2 - x)) +
		all->ray.plane_y * cos(0.005 * abs(x2 - x));
}
