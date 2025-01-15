/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:15:35 by olthorel          #+#    #+#             */
/*   Updated: 2025/01/08 10:15:35 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	apply_colors(t_fdf *fdf, t_point *point)
{
	t_color	*col;

	col = NULL;
	if (fdf->cam->color_pallet == FALSE)
	{
		if (point->color == -1)
			point->color = LINE_DEFAULT;
	}
	else
	{
		if (point->z >= 0)
		{
			col = color_pallet_init(C_LIME, C_BLUEY);
			point->color = get_color(col, absolute(point->z), \
				absolute(fdf->map->max_z));
			free(col);
		}
		else if (point->z == 0)
			point->color = C_LIME;
		else
		{
			col = color_pallet_init(C_LIME, C_ORANGY);
			point->color = get_color(col, absolute(point->z), \
				absolute(fdf->map->max_z));
			free(col);
		}
	}
}

static void	render_line(t_fdf *fdf, t_point start, t_point end)
{
	start.z *= fdf->cam->scale_z;
	end.z *= fdf->cam->scale_z;
	apply_colors(fdf, &start);
	apply_colors(fdf, &end);
	fdf->image->line = init_line(start, end, fdf);
	if (!fdf->image->line)
		close_all(fdf, 7);
	rotate(fdf->cam, fdf->image->line);
	project(fdf->cam, fdf->image->line);
	transform(fdf->cam, fdf->image->line);
	bresenham(fdf, fdf->image->line->start, fdf->image->line->end);
	free(fdf->image->line);
}

void	display_fps(t_fps *fps_data)
{
	struct timespec	current_time;
	double			elapsed_time;

	clock_gettime(CLOCK_MONOTONIC, &current_time);
	elapsed_time = (current_time.tv_sec - fps_data->last_time.tv_sec) +
                   (current_time.tv_nsec - fps_data->last_time.tv_nsec) / 1000000.0;
	fps_data->frames_count++;
	if (elapsed_time >= 1.0)
	{
		fps_data->fps = fps_data->frames_count;
		fps_data->frames_count = 0;
		fps_data->last_time = current_time;
	}
}

void	render(t_fdf *fdf)
{
	int	x;
	int	y;

	if (fdf->process == 1)
		return;
	fdf->process = 1;
	clear_image(fdf->image, MAX_PIXEL * 4);
	y = 0;
	while (y < fdf->map->max_y)
	{
		x = 0;
		while (x < fdf->map->max_x)
		{
			if (x < fdf->map->max_x - 1)
				render_line(fdf, fdf->map->coordinates[x][y], \
					fdf->map->coordinates[x + 1][y]);
			if (y < fdf->map->max_y - 1)
				render_line(fdf, fdf->map->coordinates[x][y], \
					fdf->map->coordinates[x][y + 1]);
			x++;
		}
		y++;
	}
	display_fps(&fdf->fps_data);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->image->image, 0, 0);
	print_menu(fdf);
	fdf->process = 0;
}
