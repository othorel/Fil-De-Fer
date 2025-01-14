/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:53:26 by olthorel          #+#    #+#             */
/*   Updated: 2024/12/31 15:53:26 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotate_x(t_line *line, double angle)
{
	t_point	new_start;
	t_point	new_end;

	new_start.y = line->start.y * cosf(angle) - line->start.z * sinf(angle);
	new_start.z = line->start.y * sinf(angle) + line->start.z * cosf(angle);
	line->start.y = new_start.y;
	line->start.z = new_start.z;
	new_end.y = line->end.y * cosf(angle) - line->end.z * sinf(angle);
	new_end.z = line->end.y * sinf(angle) + line->end.z * cosf(angle);
	line->end.y = new_end.y;
	line->end.z = new_end.z;
}

void	rotate_y(t_line *line, double angle)
{
	t_point	new_start;
	t_point	new_end;

	new_start.x = line->start.x * cosf(angle) + line->start.z * sinf(angle);
	new_start.z = -line->start.x * sinf(angle) + line->start.z * cosf(angle);
	line->start.x = new_start.x;
	line->start.z = new_start.z;
	new_end.x = line->end.x * cosf(angle) + line->end.z * sinf(angle);
	new_end.z = -line->end.x * sinf(angle) + line->end.z * cosf(angle);
	line->end.x = new_end.x;
	line->end.z = new_end.z;
}

void	rotate_z(t_line *line, double angle)
{
	t_point	new_start;
	t_point	new_end;

	new_start.x = line->start.x * cosf(angle) - line->start.y * sinf(angle);
	new_start.y = line->start.x * sinf(angle) + line->start.y * cosf(angle);
	line->start.x = new_start.x;
	line->start.y = new_start.y;
	new_end.x = line->end.x * cosf(angle) - line->end.y * sinf(angle);
	new_end.y = line->end.x * sinf(angle) + line->end.y * cosf(angle);
	line->end.x = new_end.x;
	line->end.y = new_end.y;
}

void	rotate(t_cam *cam, t_line *line)
{
	rotate_x(line, cam->alpha);
	rotate_y(line, cam->beta);
	rotate_z(line, cam->gamma);
}
