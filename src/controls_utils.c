/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:17:28 by olthorel          #+#    #+#             */
/*   Updated: 2024/12/13 15:07:38 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_isometric(t_fdf *prog)
{
	prog->matrix.rot_x = 0.7853982;
	prog->matrix.rot_y = 0;
	prog->matrix.rot_z = 0.6154729;
	prog->matrix.plus_z = 0.2;
}

void	set_dimetric(t_fdf *prog)
{
	prog->matrix.rot_x = 0.7853982;
	prog->matrix.rot_y = 0;
	prog->matrix.rot_z = 0.4636467;
	prog->matrix.plus_z = 0.2;
}

void	set_trimetric(t_fdf *prog)
{
	prog->matrix.rot_x = 1.047198;
	prog->matrix.rot_y = 0;
	prog->matrix.rot_z = 0.4642576;
	prog->matrix.plus_z = 0.2;
}

int	set_color(int keyboard, t_fdf *prog)
{
	if (keyboard == KEYBOARD_1)
		prog->matrix.color = 0xFFFFFF;
	else if (keyboard == KEYBOARD_2)
		prog->matrix.color = 0x008000;
	else if (keyboard == KEYBOARD_3)
		prog->matrix.color = 0xFF0000;
	else if (keyboard == KEYBOARD_4)
		prog->matrix.color = 0x1F75FE;
	else if (keyboard == KEYBOARD_5)
		prog->matrix.color = 0xFFFF00;
	else if (keyboard == KEYBOARD_6)
		prog->matrix.color = 0xFF1493;
	else if (keyboard == KEYBOARD_7)
		prog->matrix.color = 0x808080;
	else
		return (0);
	return (1);
}
