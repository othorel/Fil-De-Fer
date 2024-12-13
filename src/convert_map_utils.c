/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:11:20 by olthorel          #+#    #+#             */
/*   Updated: 2024/12/13 15:25:19 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	get_3Dmap_width(t_point3D **map3D)
{
	int	i;

	i = 0;
	while (map3D[0] && !map3D[0][i].last)
		i++;
	return (i);
}

int	get_3Dmap_height(t_point3D **map3D)
{
	int	i;

	i = 0;
	while (map3D[i])
		i++;
	return (i);
}

void	*free_map2D(t_point2D **map2D, int alloc)
{
	int	i;

	if (!alloc)
	{
		i = 0;
		while (map2D[i])
			free(map2D[i++]);
		free(map2D);
	}
	return (NULL);	
}