/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspinnet <mspinnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 17:48:07 by mspinnet          #+#    #+#             */
/*   Updated: 2021/01/22 18:14:02 by mspinnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	printscreen(t_all *all)
{
	int						i;
	static unsigned char	bmppad[3] = {0, 0, 0};

	all->screen.filesize = 54 + 3 * all->flag.r_x * all->flag.r_y;
	all->screen.img = malloc(3 * all->flag.r_x * all->flag.r_y);
	ft_memset(all->screen.img, 0, 3 * all->flag.r_x * all->flag.r_y);
	all->screen.fd = open("img.bmp", O_RDWR | O_TRUNC | O_CREAT, S_IRWXU);
	printscreen2(all);
	printscreen3(all);
	i = 0;
	while (i < all->flag.r_y)
	{
		write(all->screen.fd, all->screen.img + (all->flag.r_x *
		(all->flag.r_y - i - 1) * 3), all->flag.r_x * 3);
		write(all->screen.fd, bmppad, (4 - (all->flag.r_x * 3) % 4) % 4);
		i++;
	}
	free(all->screen.img);
	close(all->screen.fd);
}

void	printscreen2(t_all *all)
{
	int		i;
	int		j;

	i = -1;
	while (++i < all->flag.r_x)
	{
		j = -1;
		while (++j < all->flag.r_y)
		{
			all->screen.x = i;
			all->screen.y = (all->flag.r_y - 1) - j;
			all->screen.dst = all->win.addr + (all->screen.y *
				all->win.line_l + all->screen.x * (all->win.bpp / 8));
			all->screen.color = *(unsigned int *)all->screen.dst;
			all->screen.r = (all->screen.color >> 16) & 0xff;
			all->screen.g = (all->screen.color >> 8) & 0xff;
			all->screen.b = (all->screen.color) & 0xff;
			all->screen.img[(all->screen.x + all->screen.y * all->flag.r_x)
				* 3 + 2] = (unsigned char)(all->screen.r);
			all->screen.img[(all->screen.x + all->screen.y * all->flag.r_x)
				* 3 + 1] = (unsigned char)(all->screen.g);
			all->screen.img[(all->screen.x + all->screen.y * all->flag.r_x)
				* 3 + 0] = (unsigned char)(all->screen.b);
		}
	}
}

void	printscreen3(t_all *all)
{
	static unsigned char bmpfileheader[14] = {'B', 'M', 0, 0, 0,
		0, 0, 0, 0, 0, 54, 0, 0, 0};
	static unsigned char bmpinfoheader[40] = {40, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 1, 0, 24, 0};

	bmpfileheader[2] = (unsigned char)(all->screen.filesize);
	bmpfileheader[3] = (unsigned char)(all->screen.filesize >> 8);
	bmpfileheader[4] = (unsigned char)(all->screen.filesize >> 16);
	bmpfileheader[5] = (unsigned char)(all->screen.filesize >> 24);
	bmpinfoheader[4] = (unsigned char)(all->flag.r_x);
	bmpinfoheader[5] = (unsigned char)(all->flag.r_x >> 8);
	bmpinfoheader[6] = (unsigned char)(all->flag.r_x >> 16);
	bmpinfoheader[7] = (unsigned char)(all->flag.r_x >> 24);
	bmpinfoheader[8] = (unsigned char)(all->flag.r_y);
	bmpinfoheader[9] = (unsigned char)(all->flag.r_y >> 8);
	bmpinfoheader[10] = (unsigned char)(all->flag.r_y >> 16);
	bmpinfoheader[11] = (unsigned char)(all->flag.r_y >> 24);
	write(all->screen.fd, bmpfileheader, 14);
	write(all->screen.fd, bmpinfoheader, 40);
}

int		mlx_start_print(t_all *all)
{
	all->win.mlx = mlx_init();
	all->win.img = mlx_new_image(all->win.mlx, all->flag.r_x, all->flag.r_y);
	all->win.addr = mlx_get_data_addr(all->win.img, &all->win.bpp,
		&all->win.line_l, &all->win.end);
	get_addr(all);
	raycast_print(all);
	return (0);
}

int		raycast_print(t_all *all)
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
	printscreen(all);
	mlx_destroy_image(all->win.mlx, all->win.img);
	return (0);
}
