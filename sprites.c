/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspinnet <mspinnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 12:10:14 by mspinnet          #+#    #+#             */
/*   Updated: 2021/01/23 12:49:58 by mspinnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ar_sprites(t_all *all)
{
	t_point		pos;
	int			i;

	i = 0;
	all->sprite.ar = (int**)malloc(sizeof(int*) * all->sprite.number);
	all->sprite.ar == NULL ? write(1, "Error malloc!\n", 14) : 0;
	all->sprite.ar == NULL ? exit(0) : 0;
	pos.x = 0;
	while (all->map[pos.x])
	{
		pos.y = 0;
		while (all->map[pos.x][pos.y])
		{
			if (all->map[pos.x][pos.y] == '2')
			{
				all->sprite.ar[i] = (int *)malloc(sizeof(int) * 2);
				all->sprite.ar[i][0] = pos.x;
				all->sprite.ar[i][1] = pos.y;
				i++;
			}
			pos.y++;
		}
		pos.x++;
	}
}

void	sort_sprites(t_all *all)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	while (i < all->sprite.number - 1)
	{
		if (abs(((int)all->ray.pos_x - all->sprite.ar[i][0]) *
		((int)all->ray.pos_x - all->sprite.ar[i][0]) + ((int)all->ray.pos_y
		- all->sprite.ar[i][1]) * ((int)all->ray.pos_y - all->sprite.ar[i][1]))
		< abs(((int)all->ray.pos_x - all->sprite.ar[i + 1][0]) *
		((int)all->ray.pos_x - all->sprite.ar[i + 1][0]) + ((int)all->ray.pos_y
		- all->sprite.ar[i + 1][1]) * ((int)all->ray.pos_y -
		all->sprite.ar[i + 1][1])))
		{
			x = all->sprite.ar[i][0];
			y = all->sprite.ar[i][1];
			all->sprite.ar[i][0] = all->sprite.ar[i + 1][0];
			all->sprite.ar[i][1] = all->sprite.ar[i + 1][1];
			all->sprite.ar[i + 1][0] = x;
			all->sprite.ar[i + 1][1] = y;
			i = 0;
		}
		i++;
	}
}

void	sprites(t_all *all, double *zbuff)
{
	int		i;

	i = -1;
	while (++i < all->sprite.number)
	{
		sprites2(all, i);
		all->sprite.stripe = all->sprite.d_start_x - 1;
		while (++all->sprite.stripe < all->sprite.d_end_x)
		{
			all->tex.tex_x = (int)(256 * (all->sprite.stripe -
				(-all->sprite.s_width / 2 + all->sprite.s_screen_x)) *
				all->tex.tex_width / all->sprite.s_width) / 256;
			all->sprite.y = all->sprite.d_start_y;
			if (all->sprite.trans_y > 0 && all->sprite.stripe > 0 &&
			all->sprite.stripe < all->flag.r_x &&
			all->sprite.trans_y < zbuff[all->sprite.stripe])
				while (all->sprite.y < all->sprite.d_end_y)
					sprites3(all);
		}
	}
}

void	sprites2(t_all *all, int i)
{
	all->sprite.spr_x = all->sprite.ar[i][0] - all->ray.pos_x + 0.5;
	all->sprite.spr_y = all->sprite.ar[i][1] - all->ray.pos_y + 0.5;
	all->sprite.inv_d = 1.0 / (all->ray.plane_x * all->ray.dir_y -
		all->ray.dir_x * all->ray.plane_y);
	all->sprite.trans_x = all->sprite.inv_d * (all->ray.dir_y *
		all->sprite.spr_x - all->ray.dir_x * all->sprite.spr_y);
	all->sprite.trans_y = all->sprite.inv_d * (-all->ray.plane_y *
		all->sprite.spr_x + all->ray.plane_x * all->sprite.spr_y);
	all->sprite.s_screen_x = (int)((all->flag.r_x / 2) *
		(1 + all->sprite.trans_x / all->sprite.trans_y));
	all->sprite.s_height = abs((int)(all->flag.r_y / (all->sprite.trans_y)));
	all->sprite.d_start_y = -all->sprite.s_height / 2 + all->flag.r_y / 2;
	if (all->sprite.d_start_y < 0)
		all->sprite.d_start_y = 0;
	all->sprite.d_end_y = all->sprite.s_height / 2 + all->flag.r_y / 2;
	if (all->sprite.d_end_y >= all->flag.r_y)
		all->sprite.d_end_y = all->flag.r_y - 1;
	all->sprite.s_width = abs((int)(all->flag.r_y / (all->sprite.trans_y)));
	all->sprite.d_start_x = -all->sprite.s_width / 2 + all->sprite.s_screen_x;
	if (all->sprite.d_start_x < 0)
		all->sprite.d_start_x = 0;
	all->sprite.d_end_x = all->sprite.s_screen_x + all->sprite.s_width / 2;
	if (all->sprite.d_end_x >= all->flag.r_x)
		all->sprite.d_end_x = all->flag.r_x - 1;
}

void	sprites3(t_all *all)
{
	char	*dst;

	all->sprite.d = (all->sprite.y) * 256 - all->flag.r_y * 128 +
		all->sprite.s_height * 128;
	all->tex.tex_y = ((all->sprite.d * all->tex.tex_height) /
		all->sprite.s_height) / 256;
	dst = all->spr.addr + ((all->tex.tex_y * all->tex.tex_width +
		all->tex.tex_x) * (all->spr.bpp / 8));
	all->sprite.color = *(unsigned int *)dst;
	if ((all->sprite.color & 0x00FFFFFF) != 0)
		pixel_put(&all->win, all->sprite.stripe, all->sprite.y,
			all->sprite.color);
	all->sprite.y++;
}
