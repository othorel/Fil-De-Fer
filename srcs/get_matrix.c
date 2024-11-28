/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:49:41 by olthorel          #+#    #+#             */
/*   Updated: 2024/11/28 15:55:47 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point3D multiple(t_point3D *a, t_point3D *b)
{
	t_point3D	res;

	res.x = a->x * b->x + a->y * b->y + a->z * b->z;
	res.y = a->x * b->x + a->y * b->y + a->z * b->z;
	res.z = a->x * b->x + a->y * b->y + a->z * b->z;
	return (res);
}

t_point2D	get_tpoint(int x, int y)
{
	t_point2D	pos;

	pos.x = x;
	pos.y = y;
	return (pos);
}
