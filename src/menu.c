/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:11:50 by olthorel          #+#    #+#             */
/*   Updated: 2025/01/08 10:11:50 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static char	*get_projection_name(t_fdf *fdf)
{
	char	*projection;

	projection = "";
	if (fdf->cam->projection == ISOMETRIC)
		projection = "Isometric projection";
	else if (fdf->cam->projection == PERSPECTIVE)
		projection = "Perspective projection";
	else if (fdf->cam->projection == TOP)
		projection = "Top view";
	return (projection);
}

void	print_menu(t_fdf *fdf)
{
	int		y;
	char	*projection;
	void	*mlx;
	void	*win;
	char	*fps;

	y = 0;
	mlx = fdf->mlx;
	win = fdf->win;
	fps = ft_itoa(fdf->fps_data.fps);
	projection = get_projection_name(fdf);
	mlx_string_put(mlx, win, 50, y += 50, C_TEXT, projection);
	mlx_string_put(mlx, win, 50, y += 35, C_TEXT, "Press 'ESC' to close");
	mlx_string_put(mlx, win, 50, y += 35, C_TEXT, "Zoom: press '-' or '+'");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "Move: press arrow keys");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "Rotate X: press 'S' or 'W'");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "Rotate Y: press 'Q' or 'E'");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "Rotate Z: press 'A' or 'D'");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "Scale Z: press 'Z' or 'X'");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "(Z scale limited to 100%)");
	mlx_string_put(mlx, win, 50, y += 35, C_TEXT, "To change projection view:");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "Isometric: press 'I'");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "Perspective: press 'P'");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "Top View: press 'O'");
	mlx_string_put(mlx, win, 50, y += 35, C_TEXT, "Colors: press 'SPACE'");
	mlx_string_put(mlx, win, 50, y += 35, C_TEXT, "Reset view: press 'R'");
	if (fps)
	{
		mlx_string_put(mlx, win, 50, y += 35, C_TEXT, "FPS: ");
		mlx_string_put(mlx, win, 100, y, C_TEXT, fps);
		free(fps);
	}
}
