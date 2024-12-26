/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:22:52 by olthorel          #+#    #+#             */
/*   Updated: 2024/12/26 17:49:41 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>

typedef struct	s_env
{
	void				*mlx;
	void				*win;
	void				*img;
	int					width;
	int					height;
	int					min_z;
	int					max_z;
	int					max_x;
	int					max_y;
	int					space;
	char				ocean;
	struct s_cam		*cam;
	struct s_matrix3D	*p;
	struct s_matrix3D	*d2;
	struct s_color		*color_min;
	struct s_color		*color_max;	
}						t_env;

typedef struct	s_matrix3D
{
	double				x;
	double				y;
	double				z;
	struct s_matrix3D	*next;
	char				end;
		
}						t_matrix3D;

typedef struct	s_color
{
	int					r;
	int					g;
	int					b;
	int					a;
}						t_color;

typedef struct	s_cam
{
	double				x;
	double				y;
	double				z;
	double				rx;
	double				ry;
	double				rz;
	double				fov;
}						t_cam;
