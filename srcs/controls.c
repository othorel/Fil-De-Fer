/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:43:51 by olthorel          #+#    #+#             */
/*   Updated: 2024/11/28 16:34:53 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	deal_key(int keyboard, void *param)
{
	t_fdf	*prog;

	prog = (t_fdf *)param;
	if (keyboard = KEYBOARD_I)
		set_isometric(prog);
	else if (keyboard == KEYBOARD_R)
		set_dimetric(prog);
	else if (keyboard == KEYBOARD_T)
		set_trimetric(prog);
	else if (keyboard == KEYBOARD_PLUS)
		prog->matrix.plus_z += 0.2;
	else if (keyboard == KEYBOARD_MINUS)
		prog->matrix.plus_z -= 0.2;
	else if (keyboard == KEYBOARD_ESC)
		exit (EXIT_SUCCESS);
	else if (!set_color(keyboard, prog))
	{
		prog->mouse_down = 1;
		return (0);
	}
	prog->mouse_down = 0;
	return (0);
}

int	push_mouse(int keyboard, int x, int y, void *param)
{
	t_fdf	*prog;

	prog = (t_fdf *)param;
	if (keyboard == MOUSE_LEFT)
		prog->mouse_left = 1;
	else if (keyboard == MOUSE_RIGHT)
		prog->mouse_right = 1;
	else
	{
		if (keyboard == WHEEL_UP)
			prog->matrix.scale += 1.3;
		else if (keyboard == WHEEL_DOWN)
			prog->matrix.scale -= 1.3;
		if (keyboard == WHEEL_UP || keyboard == WHEEL_DOWN)
			prog->mouse_down = 0;
	}
	prog->mouse.x = x;
	prog->mouse.y = y;
	return (0);
}

int	release_mouse(int keyboard, int x, int y, void *param)
{
	t_fdf	*prog;

	prog = (t_fdf *)param;
	if (keyboard == MOUSE_LEFT)
		prog->mouse_left = 0;
	else if (keyboard == MOUSE_RIGHT)
		prog->mouse_right = 0;
	prog->mouse.x = x;
	prog->mouse.y = y;
	return (0);
}

int	move_mouse(int x, int y, void *param)
{
	t_fdf	*prog;

	prog = (t_fdf *)param;
	if (prog->mouse_right)
	{
		prog->matrix.rot_x += (prog->mouse.y - y) * 150;
		prog->matrix.rot_y += (x - prog->mouse.x) * 150;
	}
	if (prog->mouse_left)
	{
		prog->matrix.t_x += x - prog->mouse.x;
		prog->matrix.t_y += y - prog->mouse.y;
	}
	if (prog->mouse_right || prog->mouse_left)
	{
		prog->mouse_down = 0;
		prog->mouse.x = x;
		prog->mouse.y = y;
	}
	return (0);
}
