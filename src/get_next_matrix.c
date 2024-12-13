/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:22:11 by olthorel          #+#    #+#             */
/*   Updated: 2024/12/12 13:26:51 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	get_3D_height(char *filename)
{
	int		fd;
	int		height;
	char	*line;
	
	height = 0;
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

static int	get_3D_width(char *filename)
{
	int		fd;
	int		width;
	char	*line;
	int		i;
	
	width = 1;
	i = 0;
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line && line[i])
	{
		if ((line[i] == ' ' && line[i - 1] != ' ') || !line[i + 1])
			width++;
		i++;
	}
	free(line);
	close(fd);
	return (width);
}

static void	alloc_map3D(t_point3D **map3D, int width, int height)
{
	int		i;
	int		j;
	
	i = 0;
	*map3D = (t_point3D **)malloc(sizeof(t_point3D *) * (height + 1));
	if (!*map3D)
		return (NULL);
	while (i < height)
	{
		map3D[i] = (t_point3D *)malloc(sizeof(t_point3D) * (width));
		if (!map3D[i])
			return (free_map3D(map3D), NULL);
		j = 0;
		while (j < width)
		{
			map3D[i][j].x = j;
			map3D[i][j].y = i;
			map3D[i][j].z = 0;
			j++;
		}
		map3D[i][j].last = 1;
		i++;
	}
}

void	parse_matrix(char *filename, t_point3D **matrix)
{
	int		fd;
	int		i;
	int		j;
	int		k;
	char	*line;
	
	alloc_map3D(matrix, get_3D_width(filename), get_3D_height(filename));
	i = 0;
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		j = 0;
		k = -1;
		while (line[k])
			if (line[k] >= 48 && line[k] <= 57)
				if (k == 0 || line[k - 1] == ' ')
					matrix[i][j++].z = ft_atoi(&line[k]);
		k++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}