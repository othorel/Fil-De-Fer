/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:22:52 by olthorel          #+#    #+#             */
/*   Updated: 2024/11/28 16:32:45 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include "keyboard.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

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

#endif