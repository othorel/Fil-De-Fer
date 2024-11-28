/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:45:53 by olthorel          #+#    #+#             */
/*   Updated: 2024/11/28 15:53:45 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point2D	**alloc_map2D(t_point3D **map3D)
{
	int			width;
	int			height;
	int			i;
	int			j;
	t_point2D	**map2D;

	width = get_3D_width(map3D);
	height = get_3D_height(map3D);
	i = 0;
	map2D = (t_point2D **)malloc(sizeof(t_point2D *) * (height + 1));
	if (!map2D)
		return (NULL);
	while (i < height)
	{
		map2D[i] = (t_point2D *)malloc(sizeof(t_point2D) * (width));
		if (!map2D[i])
			return (free_map2D(map2D), NULL);
		j = 0;
		while (j < width - 1)
			map2D[i][j++].last = 0;
		map2D[i][j].last = 1;
		i++;
	}
	return (map2D);
}

void	convert_map(t_fdf *prog, int alloc)
{
	int			i;
	int			j;
	t_point3D	**rot;
	t_point3D	pro;

	free_2D_map(&prog->matrix.matrix2D, prog);
	prog->matrix.matrix2D = alloc_map2D(prog->matrix.matrix3D);
	rot = get_royxyz(*prog);
	if (!prog->matrix.matrix2D || !rot)
		exit (EXIT_FAILURE);
	i = 0;
	while (prog->matrix.matrix2D[i])
	{
		j = 0;
		while (!prog->matrix.matrix2D[i][j].last)
		{
			pro = prog->matrix.matrix3D[i][j];
			pro.z = prog->matrix.matrix3D[i][j].z + prog->matrix.plus_z;
			pro = multiple(rot[2], muliple(rot[1], multiple(rot[0], pro)));
			prog->matrix.matrix2D[i][j].x = pro.x * prog->matrix.scale + prog->matrix.t_x;
			prog->matrix.matrix2D[i][j].y = pro.y * prog->matrix.scale + prog->matrix.t_y;
		}
		i++;
	}
	free(rot);
}
