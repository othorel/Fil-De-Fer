/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:22:52 by olthorel          #+#    #+#             */
/*   Updated: 2025/01/02 15:34:50 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

# define WIN_WIDTH 2000
# define WIN_HEIGHT 1000
# define COLOR 0x33DFFF
# define WIN_NAME "FDF - olthorel"

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
}				t_point;

typedef struct s_fdf
{
	int			width;
	int			height;
	t_point		**map;
	void		*mlx;
	void		*win;
}				t_fdf;

void	clean_up(t_fdf *mlx, t_fdf *win);
int		close_windows(void *param);
int		key_hook(int key, void *param);

void	draw_line(void *mlx, void *win, t_point start, t_point end, int color);
void	draw_grid(void *mlx, void *win, int color);
void	draw_map(void *mlx, void *win, t_fdf *data);

void	apply_isometric_projection(t_point *p, int scale, int offset_x, int offset_y);
int 	get_color_by_z(int z);

void	free_ft_split(char **tab);
int		count_columns(char *line);
int		init_map_memory(t_fdf *mlx, int height, int width);
int		fill_map(t_fdf *mlx, char *file);
int		read_map(char *file, t_fdf *mlx);

#endif