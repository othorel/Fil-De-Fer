/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rotor_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:57:58 by olthorel          #+#    #+#             */
/*   Updated: 2024/11/28 16:29:45 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_point3D	*get_rotor_x(t_matrix matrix)
{
	t_point3D	*rotor;
	
	rotor = (t_point3D *)malloc(sizeof(t_point3D) * 3);
	if (!rotor)
		return (NULL);
	rotor[0].x = 1;
	rotor[0].y = 0;
	rotor[0].z = 0;
	rotor[1].x = 0;
	rotor[1].y = cos(matrix.rot_x);
	rotor[1].z = -sin(matrix.rot_x);
	rotor[2].x = 0;
	rotor[2].y = sin(matrix.rot_x);
	rotor[2].z = cos(matrix.rot_x);
	return (rotor);
}

static t_point3D	*get_rotor_y(t_matrix matrix)
{
	t_point3D	*rotor;
	
	rotor = (t_point3D *)malloc(sizeof(t_point3D) * 3);
	if (!rotor)
		return (NULL);
	rotor[0].x = cos(matrix.rot_y);
	rotor[0].y = 0;
	rotor[0].z = sin(matrix.rot_y);
	rotor[1].x = 0;
	rotor[1].y = 1;
	rotor[1].z = 0;
	rotor[2].x = -sin(matrix.rot_y);
	rotor[2].y = 0;
	rotor[2].z = cos(matrix.rot_y);
	return (rotor);
}

static t_point3D	*get_rotor_z(t_matrix matrix)
{
	t_point3D	*rotor;
	
	rotor = (t_point3D *)malloc(sizeof(t_point3D) * 3);
	if (!rotor)
		return (NULL);
	rotor[0].x = cos(matrix.rot_z);
	rotor[0].y = -sin(matrix.rot_z);
	rotor[0].z = 0;
	rotor[1].x = sin(matrix.rot_z);
	rotor[1].y = cos(matrix.rot_z);
	rotor[1].z = 0;
	rotor[2].x = 0;
	rotor[2].y = 0;
	rotor[2].z = 1;
	return (rotor);
}
static t_point3D	**get_rotor_matrix(t_matrix matrix)
{
	t_point3D	**rotor;
	
	rotor = (t_point3D **)malloc(sizeof(t_point3D *) * 3);
	if (!rotor)
		return (NULL);
	rotor[0] = get_rotor_x(matrix);
	rotor[1] = get_rotor_y(matrix);
	rotor[2] = get_rotor_z(matrix);
	if (!rotor[0] || !rotor[1] || !rotor[2])
		return (free(rotor), NULL);
	return (rotor);
}


void	free_rotor_matrix(t_point3D **rotor)
{
	free(rotor[0]);
	free(rotor[1]);
	free(rotor[2]);
	free(rotor);
	return (NULL);
}