/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_move_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspinnet <mspinnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 12:19:23 by mspinnet          #+#    #+#             */
/*   Updated: 2021/01/19 20:01:48 by mspinnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	key_press_w(t_all *all)
{
	if (all->map[(int)(all->ray.pos_x + all->ray.dir_x * 0.07)]
	[(int)all->ray.pos_y] != '1' &&
	all->map[(int)(all->ray.pos_x + all->ray.dir_x * 0.07)]
	[(int)all->ray.pos_y] != '2')
		all->ray.pos_x += all->ray.dir_x * 0.07;
	if (all->map[(int)(all->ray.pos_x)]
	[(int)(all->ray.pos_y + all->ray.dir_y * 0.07)] != '1' &&
	all->map[(int)(all->ray.pos_x)]
	[(int)(all->ray.pos_y + all->ray.dir_y * 0.07)] != '2')
		all->ray.pos_y += all->ray.dir_y * 0.07;
}

void	key_press_s(t_all *all)
{
	if (all->map[(int)(all->ray.pos_x - all->ray.dir_x * 0.07)]
	[(int)all->ray.pos_y] != '1' &&
	all->map[(int)(all->ray.pos_x - all->ray.dir_x * 0.07)]
	[(int)all->ray.pos_y] != '2')
		all->ray.pos_x -= all->ray.dir_x * 0.07;
	if (all->map[(int)(all->ray.pos_x)]
	[(int)(all->ray.pos_y - all->ray.dir_y * 0.07)] != '1' &&
	all->map[(int)(all->ray.pos_x)]
	[(int)(all->ray.pos_y - all->ray.dir_y * 0.07)] != '2')
		all->ray.pos_y -= all->ray.dir_y * 0.07;
}

void	key_press_a(t_all *all)
{
	if (all->map[(int)(all->ray.pos_x - all->ray.plane_x * 0.07)]
	[(int)all->ray.pos_y] != '1' &&
	all->map[(int)(all->ray.pos_x - all->ray.plane_x * 0.07)]
	[(int)all->ray.pos_y] != '2')
		all->ray.pos_x -= all->ray.plane_x * 0.07;
	if (all->map[(int)(all->ray.pos_x)]
	[(int)(all->ray.pos_y - all->ray.plane_y * 0.07)] != '1' &&
	all->map[(int)(all->ray.pos_x)]
	[(int)(all->ray.pos_y - all->ray.plane_y * 0.07)] != '2')
		all->ray.pos_y -= all->ray.plane_y * 0.07;
}

void	key_press_d(t_all *all)
{
	if (all->map[(int)(all->ray.pos_x + all->ray.dir_y * 0.07)]
	[(int)all->ray.pos_y] != '1' &&
	all->map[(int)(all->ray.pos_x + all->ray.dir_y * 0.07)]
	[(int)all->ray.pos_y] != '2')
		all->ray.pos_x += all->ray.dir_y * 0.07;
	if (all->map[(int)(all->ray.pos_x)]
	[(int)(all->ray.pos_y - all->ray.dir_x * 0.07)] != '1' &&
	all->map[(int)(all->ray.pos_x)]
	[(int)(all->ray.pos_y - all->ray.dir_x * 0.07)] != '2')
		all->ray.pos_y -= all->ray.dir_x * 0.07;
}

void	key_press_left(t_all *all)
{
	all->ray.old_dir_x = all->ray.dir_x;
	all->ray.dir_x = all->ray.dir_x * cos(0.045) - all->ray.dir_y * sin(0.045);
	all->ray.dir_y = all->ray.old_dir_x * sin(0.045) +
		all->ray.dir_y * cos(0.045);
	all->ray.old_plane_x = all->ray.plane_x;
	all->ray.plane_x = all->ray.plane_x * cos(0.045) -
		all->ray.plane_y * sin(0.045);
	all->ray.plane_y = all->ray.old_plane_x * sin(0.045) +
		all->ray.plane_y * cos(0.045);
}
