/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:50:03 by olthorel          #+#    #+#             */
/*   Updated: 2025/01/08 09:50:03 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	close_coordinates(t_point **coordinates, int width)
{
	int	i;

	i = 0;
	while (i < width)
	{
		free(coordinates[i]);
		i++;
	}
	free(coordinates);
}

void	close_all(t_fdf *fdf, int exit_code)
{
	fdf = NULL;
	if (!fdf)
	{
		error(exit_code);
		return;
	}
	if (fdf->map)
	{
		if (fdf->map->coordinates)
            close_coordinates(fdf->map->coordinates, fdf->map->max_x);
		free(fdf->map);
	}
	if (fdf->image)
	{
		if (fdf->image->image)
            mlx_destroy_image(fdf->mlx, fdf->image->image);
		free(fdf->image);
	}
	if (fdf->cam)
        free(fdf->cam);
	if (fdf->win)
		mlx_destroy_window(fdf->mlx, fdf->win);
	if (fdf->mlx)
		free(fdf->mlx);
	free(fdf);
	error(exit_code);
}

void	close_map(t_fdf *fdf, int exit_code)
{
	fdf = NULL;
	if (fdf)
	{
		if (fdf->map)
		{
			if (fdf->map->coordinates)
				close_coordinates(fdf->map->coordinates, fdf->map->max_x);
			free(fdf->map);
		}
		if (fdf->win)
			mlx_destroy_window(fdf->mlx, fdf->win);
		if (fdf->mlx)
			mlx_destroy_display(fdf->mlx);
		free(fdf);
	}
	error(exit_code);
}

int handle_close(int keycode, t_fdf *fdf)
{
    (void)keycode;
    if (fdf)
		close_all(fdf, 0);
    exit(0);
}
