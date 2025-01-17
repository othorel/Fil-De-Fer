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

static void	display_map_info_line(t_fdf *fdf, int *line, char *str, int nbr)
{
	if (line && fdf)
	{
		print_str(fdf, 30, *line, str);
		print_nbr(fdf, 100, *line, nbr);
		*line += 30;
	}
}

static void	map_info(t_fdf *fdf)
{
	int		line;

	line = 100;
	print_str(fdf, 30, line, "//// MAP INFO ////");
	line += 30;
	display_map_info_line(fdf, &line, "Width :", fdf->map->max_x);
	display_map_info_line(fdf, &line, "Height :", fdf->map->max_y);
	display_map_info_line(fdf, &line, "Max Z :", fdf->map->max_z);
	display_map_info_line(fdf, &line, "Min Z :", fdf->map->min_z);
	display_map_info_line(fdf, &line, "Max X :", fdf->map->max_x);
	display_map_info_line(fdf, &line, "Max Y :", fdf->map->max_y);
}

static void	display_control(t_fdf *fdf, int *line, char *str)
{
	if (line && fdf)
	{
		print_str(fdf, 30, *line, str);
		*line += 30;
	}
}

static void	draw_info(t_fdf *fdf)
{
	int		line;

	line = 350;
	print_str(fdf, 30, line, "//// CONTROLS ////");
	line += 30;
	display_control(fdf, &line, "Press 'ESC' or 'X' to close");
	display_control(fdf, &line, "Zoom : press '-' or '+'");
	display_control(fdf, &line, "Rotate X : press 'S' or 'W'");
	display_control(fdf, &line, "Rotate Y : press 'Q' or 'E'");
	display_control(fdf, &line, "Rotate Z : press 'A' or 'D'");
	display_control(fdf, &line, "Scale Z : press 'Z' or 'X'");
	display_control(fdf, &line, "Change projection view :");
	display_control(fdf, &line, "Isometric : press 'I'");
	display_control(fdf, &line, "Perspective : press 'P'");
	display_control(fdf, &line, "Top View : press 'O'");
	display_control(fdf, &line, "Colors : press 'SPACE'");
	display_control(fdf, &line, "Reset view : press 'R'");
}

void	print_menu(t_fdf *fdf)
{
	int		line;
	char	*projection;

	line = 30;
	projection = get_projection_name(fdf);
	print_str(fdf, 30, line, "//// PROJECTION ////");
	line += 30;
	print_str(fdf, 30, line, projection);
	line += 30;
	map_info(fdf);
	draw_info(fdf);
}
