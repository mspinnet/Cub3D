/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspinnet <mspinnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 12:21:41 by mspinnet          #+#    #+#             */
/*   Updated: 2021/01/23 12:27:14 by mspinnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "./libft/libft.h"
# include "./minilibx_opengl_20191021/mlx.h"
# include "./get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>

typedef struct	s_flags
{
	int		r_x;
	int		r_y;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*s;
	int		f[3];
	int		c[3];
	int		j;
	int		err;
}				t_flags;

typedef struct	s_tex
{
	double	wallx;
	int		tex_x;
	int		tex_width;
	int		tex_height;
	double	step;
	double	tex_pos;
	int		tex_y;
}				t_tex;

typedef struct	s_arg
{
	int		j;
	int		fd;
	int		gnl;
	char	*str;
	char	*line;
	char	*str2;
}				t_arg;

typedef struct	s_window
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
	int		bpp;
	int		line_l;
	int		end;
}				t_window;

typedef struct	s_sprite
{
	int		number;
	int		**ar;
	double	spr_x;
	double	spr_y;
	double	inv_d;
	double	trans_x;
	double	trans_y;
	int		s_screen_x;
	int		s_height;
	int		s_width;
	int		d_start_x;
	int		d_end_x;
	int		d_start_y;
	int		d_end_y;
	int		stripe;
	int		y;
	int		d;
	int		color;
}				t_sprite;

typedef struct	s_ray
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	old_dir_x;
	double	old_plane_x;
	double	plane_x;
	double	plane_y;
	double	cam_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	pwd;
	int		step_x;
	int		step_y;
	int		line_h;
	int		d_start;
	int		d_end;
	int		key_flag_s;
	int		key_flag_a;
	int		key_flag_w;
	int		key_flag_d;
	int		key_flag_left;
	int		key_flag_right;
	int		texture;
	int		side;
	int		hit;
	int		x;
}				t_ray;

typedef struct	s_print
{
	int				fd;
	unsigned char	*img;
	int				x;
	int				y;
	int				r;
	int				g;
	int				b;
	int				color;
	char			*dst;
	int				filesize;
}				t_print;

typedef struct	s_all
{
	t_window	win;
	t_flags		flag;
	t_ray		ray;
	t_tex		tex;
	t_window	left;
	t_window	right;
	t_window	up;
	t_window	down;
	t_window	spr;
	t_sprite	sprite;
	t_print		screen;
	t_list		*head;
	char		**map;
}				t_all;

typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

char			**make_map(t_list **head, int size);
t_flags			make_flags(void);
int				is_space(char **map, int j, int i);
t_flags			make_value_r(char **map, t_flags flag, int i, int j);
t_flags			make_value_text(char **m, int j, int i, t_flags f);
t_flags			make_value_f(char **map, int j, int i, t_flags flag);
t_flags			make_value_c(char **map, int j, int i, t_flags flag);
t_flags			make_valueall(char **m, t_flags flag);
char			*make_all(char *str);
int				delitel(char *str);
int				map_count1(char *str, int i, int count);
int				map_count(char *str);
int				map_valid2(char **m);
char			**map_valid(char *str2, t_flags flag);
t_flags			errors(t_flags f);
void			pixel_put(t_window *data, int x, int y, int color);
int				raycast(t_all *all);
void			init_player_3d(t_all *all);
int				mlx_start(t_all *all);
void			ray_init(t_all *all);
int				key_hook(int keycode, t_window *vars);
int				key_press2(int x, int y, t_all *all);
int				key_hook2(int x, int y, t_window *vars);
int				key_flags(int keycode, t_all *all);
int				key_flags2(int keycode, t_all *all);
void			key_flags3(t_all *all);
void			key_press_w(t_all *all);
void			key_press_a(t_all *all);
void			key_press_s(t_all *all);
void			key_press_d(t_all *all);
int				move_flag_check(t_all *all);
void			key_press_left(t_all *all);
void			key_press_right(t_all *all);
int				get_color(t_all *all);
void			get_addr(t_all *all);
void			get_f_c(t_all *all, int x);
void			ar_sprites(t_all *all);
void			sprites(t_all *all, double *zbuff);
void			sprites2(t_all *all, int i);
void			sort_sprites(t_all *all);
void			sprites3(t_all *all);
void			raycast_init(t_all *all, int x);
void			raycast_step(t_all *all);
void			raycast_hit(t_all *all);
void			raycast_tex_init(t_all *all);
void			raycast_tex(t_all *all, int x);
void			init_if_w(t_all *all, t_point pos);
void			init_if_s(t_all *all, t_point pos);
void			init_if_e(t_all *all, t_point pos);
void			init_if_n(t_all *all, t_point pos);
int				close_window(t_all *all);
void			make_list(t_all *all, t_arg *arg, char *str);
void			printscreen(t_all *all);
void			printscreen2(t_all *all);
void			printscreen3(t_all *all);
int				mlx_start_print(t_all *all);
int				raycast_print(t_all *all);
void			formain2(t_all *all, t_arg *arg, char *str);
void			mouse_move_right(t_all *all, int x, int x2);
void			mouse_move_left(t_all *all, int x, int x2);

#endif
