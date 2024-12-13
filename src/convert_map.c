/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:45:53 by olthorel          #+#    #+#             */
/*   Updated: 2024/12/13 15:44:05 by olthorel         ###   ########.fr       */
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

	width = get_3Dmap_width(map3D);
	height = get_3Dmap_height(map3D);
	i = 0;
	map2D = (t_point2D **)malloc(sizeof(t_point2D *) * (height));
	if (!map2D)
		return (NULL);
	while (i < height)
	{
		map2D[i] = (t_point2D *)malloc(sizeof(t_point2D) * (width));
		if (!map2D[i])
			exit (EXIT_FAILURE);
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

	free_map2D(prog->matrix.matrix2D, alloc);
	prog->matrix.matrix2D = alloc_map2D(prog->matrix.matrix3D);
	rot = get_rotor_matrix(prog->matrix);
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
			prog->matrix.matrix2D[i][j].x = pro.x * prog->matrix.scale + prog->matrix.t_x;
			prog->matrix.matrix2D[i][j].y = pro.y * prog->matrix.scale + prog->matrix.t_y;
		}
		i++;
	}
	free(rot);
}
