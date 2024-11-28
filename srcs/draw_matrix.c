/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:18:03 by olthorel          #+#    #+#             */
/*   Updated: 2024/11/28 16:38:35 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_matrix(t_point2D **matrix, t_mlx *mlx, int color)
{
	int	x;
	int	y;

	x = 0;
	while (matrix[x])
	{
		y = 0;
		while (!matrix[x][y].last)
		{
			if (matrix[x + 1])
				draw_line(mlx, matrix[x][y], matrix[x + 1][y], color);
			if (!matrix[x][y + 1].last)
				draw_line(mlx, matrix[x][y], matrix[x][y + 1], color);
			y++;
		}
		x++;
	}
}

void	draw_matrix2(t_fdf *prog)
{
	if (!prog->mouse_down)
	{
		img_init_background(&prog->mlx, prog->mlx.width, prog->mlx.height,
			0x000000);
		convert_map(&prog->matrix, 1);
		draw_matrix(prog->matrix.matrix2D, &prog->mlx, prog->matrix.color);
		mlx_put_image_to_window(prog->mlx, prog->win, prog->img.img,
			prog->img.pos.x, prog->img.pos.y);
	}
	prog->mouse_down = 1;
}

void	draw_carre(t_fdf *prog, t_point2D pos, int size, int color)
{
	int	x;
	int	y;

	x = pos.x;
	while (x < pos.x + size)
	{
		y = pos.y;
		while (y < pos.y + size)
		{
			mlx_pixel_put(prog->mlx, prog->win, x, y, color);
			y++;
		}
		x++;
	}
}

void	draw_rectangle(t_fdf *prog, t_point2D left, t_point2D right, int color)
{
	int	x;
	int	y;

	x = left.x;
	while (x < right.x)
	{
		y = left.y;
		while (y < right.y)
		{
			mlx_pixel_put(prog->mlx, prog->win, x, y, color);
			y++;
		}
		x++;
	}
}
