/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:17:28 by olthorel          #+#    #+#             */
/*   Updated: 2024/11/28 14:06:36 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_isometric(t_fdf *prog)
{
	prog->matrix.rot_x = 0.523599;
	prog->matrix.rot_y = 0;
	prog->matrix.rot_z = 0.523599;
	prog->matrix.t_x = 0.2;
}

void	set_dimetric(t_fdf *prog)
{
	prog->matrix.rot_x = 0.523599;
	prog->matrix.rot_y = 0;
	prog->matrix.rot_z = 0.523599;
	prog->matrix.t_x = 0.2;
}

void	set_trimetric(t_fdf *prog)
{
	prog->matrix.rot_x = 0.523599;
	prog->matrix.rot_y = 0;
	prog->matrix.rot_z = 0.523599;
	prog->matrix.t_x = 0.2;
}

int	set_color(int keyboard, t_fdf *prog)
{
	if (keyboard == KEYBOARD_1)
		prog->matrix.color = 0x00FF0000;
	else if (keyboard == KEYBOARD_2)
		prog->matrix.color = 0x0000FF00;
	else if (keyboard == KEYBOARD_3)
		prog->matrix.color = 0x000000FF;
	else if (keyboard == KEYBOARD_4)
		prog->matrix.color = 0x00FFFF00;
	else if (keyboard == KEYBOARD_5)
		prog->matrix.color = 0x00FF00FF;
	else if (keyboard == KEYBOARD_6)
		prog->matrix.color = 0x0000FFFF;
	else if (keyboard == KEYBOARD_7)
		prog->matrix.color = 0x00FFFFFF;
	else
		return (0);
	return (1);
}
