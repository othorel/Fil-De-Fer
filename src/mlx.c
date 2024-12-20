/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:53:35 by olthorel          #+#    #+#             */
/*   Updated: 2024/12/13 17:28:27 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	img_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;
	int		i;

	if (x >= mlx->width || x < 0 || y >= mlx->height || y < 0)
		return ;
	i = mlx->bits_per_pixel - 8;
	dst = mlx->buffer + (y * mlx->bits_per_line + x * (mlx->bits_per_pixel / 8));
	while (i >= 0)
	{
		if (mlx->endian != 0)
			*dst++ = (color >> i) & 0xFF;
		else
			*dst++ = (color >> (mlx->bits_per_pixel - 8 - i)) & 0xFF;
		i -= 8;
	}
}

void	mlx_init_background(t_mlx *mlx, int width, int height, int color)
{
	int	x;
	int	y;

	x = 0;
	while (x < width)
	{
		y = 0;
		while (y < height)
		{
			img_pixel_put(mlx, x, y, color);
			y++;
		}
		x++;
	}
}

void	mlx_put_line(t_mlx *mlx, t_point2D a, t_point2D b, int color)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	
	dx = fabs(b.x - a.x);
	dy = fabs(b.y - a.y);
	err = dx - dy;
	if (a.x < b.x)
		sx = 1;
	else
		sx = -1;
	if (a.y < b.y)
		sy = 1;
	else
		sy = -1;
	while (a.x != b.x || a.y != b.y)
	{
		img_pixel_put(mlx, a.x, a.y, color);
		if (2 * err > -dy)
		{
			err -= dy;
			a.x += sx;
		}
		if (2 * err < dx)
		{
			err += dx;
			a.y += sy;
		}
	}
}
