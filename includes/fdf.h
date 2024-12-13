/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:22:52 by olthorel          #+#    #+#             */
/*   Updated: 2024/12/13 15:52:08 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "keyboard.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_point2D
{
	double	x;
	double	y;
	int		last;
}			t_point2D;

typedef struct s_point3D
{
	double	x;
	double	y;
	double	z;
	int		last;
}			t_point3D;

typedef struct s_mlx
{
	void	*img;
	int		bits_per_pixel;
	int		bits_per_line;
	int		endian;
	char	*buffer;
	int		width;
	int		height;
	t_point2D	pos;
}			t_mlx;

typedef struct s_matrix
{
	t_point2D	**matrix2D;
	t_point3D	**matrix3D;
	int			t_x;
	int			t_y;
	double		rot_x;
	double		rot_y;
	double		rot_z;
	double		plus_z;
	double		scale;
	int			color;
}			t_matrix;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	t_mlx	img;
	t_matrix	matrix;
	t_point2D	mouse;
	int		mouse_down;
	int		mouse_right;
	int		mouse_left;
	char	*filename;
}			t_fdf;

void	set_isometric(t_fdf *prog);
void	set_dimetric(t_fdf *prog);
void	set_trimetric(t_fdf *prog);
int		set_color(int keyboard, t_fdf *prog);

int	deal_key(int keyboard, void *param);
int	push_mouse(int keyboard, int x, int y, void *param);
int	release_mouse(int keyboard, int x, int y, void *param);
int move_mouse(int x, int y, void *param);

int get_3Dmap_width(t_point3D **map3D);
int get_3Dmap_height(t_point3D **map3D);
void	*free_map2D(t_point2D **map2D, int alloc);

t_point2D	**alloc_map2D(t_point3D **map3D);
void	convert_map(t_fdf *prog, int alloc);

void	draw_matrix(t_point2D **matrix, t_mlx *mlx, int color);
void draw_matrix2(t_fdf *prog);
void draw_carre(t_fdf *prog, t_point2D pos, int size, int color);
void draw_rectangle(t_fdf *prog, t_point2D left, t_point2D right, int color);

void draw_order(t_fdf *prog);
void draw_color_order(t_fdf *prog);

t_point3D multiple(t_point3D *a, t_point3D *b);
t_point2D get_tpoint(int x, int y);

void	parse_matrix(char *filename, t_point3D **matrix);

void	free_rotor_matrix(t_point3D **rotor);

void img_pixel_put(t_mlx *mlx, int x, int y, int color);
void mlx_init_background(t_mlx *mlx, int width, int height, int color);
void mlx_put_line(t_mlx *mlx, t_point2D a, t_point2D b, int color);

t_point3D	**get_rotor_matrix(t_matrix matrix);


#endif