/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspinnet <mspinnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 12:12:43 by mspinnet          #+#    #+#             */
/*   Updated: 2021/01/23 12:49:36 by mspinnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	pixel_put(t_window *win, int x, int y, int color)
{
	char	*dst;

	dst = win->addr + (y * win->line_l + x * (win->bpp / 8));
	*(unsigned int*)dst = color;
}

void	get_f_c(t_all *all, int x)
{
	int		y;

	y = all->flag.r_x / 2;
	if (x < all->flag.r_y / 2)
		while (y < all->flag.r_x)
			pixel_put(&all->win, y++, x, (((all->flag.c[0] & 0xff) << 16) +
			((all->flag.c[1] & 0xff) << 8) + (all->flag.c[2] & 0xff)));
	y = 0;
	if (x < all->flag.r_x / 2)
		while (y < all->flag.r_y / 2)
			pixel_put(&all->win, x, y++, (((all->flag.c[0] & 0xff) << 16) +
			((all->flag.c[1] & 0xff) << 8) + (all->flag.c[2] & 0xff)));
	y = all->flag.r_y / 2;
	if (x < all->flag.r_x)
		while (y < all->flag.r_y)
			pixel_put(&all->win, x, y++, (((all->flag.f[0] & 0xff) << 16) +
			((all->flag.f[1] & 0xff) << 8) + (all->flag.f[2] & 0xff)));
}

int		get_color(t_all *all)
{
	char	*dst;
	int		color;

	if ((int)all->ray.pos_y > all->ray.map_y && all->ray.side == 1)
		dst = all->left.addr + (all->tex.tex_y * all->left.line_l +
		all->tex.tex_x * (all->left.bpp / 8));
	if ((int)all->ray.pos_y < all->ray.map_y && all->ray.side == 1)
		dst = all->right.addr + (all->tex.tex_y * all->right.line_l +
		all->tex.tex_x * (all->right.bpp / 8));
	if ((int)all->ray.pos_x > all->ray.map_x && all->ray.side == 0)
		dst = all->up.addr + (all->tex.tex_y * all->up.line_l +
		all->tex.tex_x * (all->up.bpp / 8));
	if ((int)all->ray.pos_x < all->ray.map_x && all->ray.side == 0)
		dst = all->down.addr + (all->tex.tex_y * all->down.line_l +
		all->tex.tex_x * (all->down.bpp / 8));
	color = *(unsigned int *)dst;
	return (color);
}
