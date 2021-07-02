/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspinnet <mspinnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 14:11:06 by mspinnet          #+#    #+#             */
/*   Updated: 2021/01/23 12:50:12 by mspinnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ray_init(t_all *all)
{
	all->sprite.number = 0;
	init_player_3d(all);
	ar_sprites(all);
}

int		close_window(t_all *all)
{
	(void)all;
	exit(0);
}

void	get_addr(t_all *all)
{
	all->left.img = mlx_xpm_file_to_image(all->win.mlx,
		all->flag.we, &all->tex.tex_width, &all->tex.tex_height);
	all->left.addr = mlx_get_data_addr(all->left.img,
		&all->left.bpp, &all->left.line_l, &all->left.end);
	all->right.img = mlx_xpm_file_to_image(all->win.mlx,
		all->flag.ea, &all->tex.tex_width, &all->tex.tex_height);
	all->right.addr = mlx_get_data_addr(all->right.img,
		&all->right.bpp, &all->right.line_l, &all->right.end);
	all->up.img = mlx_xpm_file_to_image(all->win.mlx,
		all->flag.no, &all->tex.tex_width, &all->tex.tex_height);
	all->up.addr = mlx_get_data_addr(all->up.img,
		&all->up.bpp, &all->up.line_l, &all->up.end);
	all->down.img = mlx_xpm_file_to_image(all->win.mlx,
		all->flag.so, &all->tex.tex_width, &all->tex.tex_height);
	all->down.addr = mlx_get_data_addr(all->down.img,
		&all->down.bpp, &all->down.line_l, &all->down.end);
	all->spr.img = mlx_xpm_file_to_image(all->win.mlx,
		all->flag.s, &all->tex.tex_width, &all->tex.tex_height);
	all->spr.addr = mlx_get_data_addr(all->spr.img,
		&all->spr.bpp, &all->spr.line_l, &all->spr.end);
}

int		raycast(t_all *all)
{
	double	zbuff[all->flag.r_x];

	move_flag_check(all);
	all->ray.x = 0;
	while (all->ray.x < all->flag.r_x)
	{
		raycast_init(all, all->ray.x);
		raycast_step(all);
		raycast_hit(all);
		raycast_tex_init(all);
		get_f_c(all, all->ray.x);
		raycast_tex(all, all->ray.x);
		zbuff[all->ray.x] = all->ray.pwd;
		all->ray.x++;
	}
	sort_sprites(all);
	sprites(all, zbuff);
	mlx_put_image_to_window(all->win.mlx, all->win.win, all->win.img, 0, 0);
	mlx_destroy_image(all->win.mlx, all->win.img);
	all->win.img = mlx_new_image(all->win.mlx, all->flag.r_x, all->flag.r_y);
	all->win.addr = mlx_get_data_addr(all->win.img, &all->win.bpp,
		&all->win.line_l, &all->win.end);
	return (0);
}

int		mlx_start(t_all *all)
{
	all->win.mlx = mlx_init();
	all->win.win = mlx_new_window(all->win.mlx, all->flag.r_x,
		all->flag.r_y, "test");
	all->win.img = mlx_new_image(all->win.mlx, all->flag.r_x, all->flag.r_y);
	all->win.addr = mlx_get_data_addr(all->win.img, &all->win.bpp,
		&all->win.line_l, &all->win.end);
	get_addr(all);
	mlx_hook(all->win.win, 2, 0, key_flags, all);
	mlx_hook(all->win.win, 3, 0, key_flags2, all);
	mlx_hook(all->win.win, 6, 0, key_press2, all);
	mlx_hook(all->win.win, 17, 0, close_window, all);
	mlx_loop_hook(all->win.mlx, raycast, all);
	mlx_loop(all->win.mlx);
	return (0);
}
