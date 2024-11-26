/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:33:14 by olthorel          #+#    #+#             */
/*   Updated: 2024/11/26 17:51:41 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	**alloc_matrix(int width, int height)
{
	int	**matrix;
	int	i;
	
	i = 0;
	matrix = (int **)malloc(sizeof(int *) * height);
	if (!matrix)
		return (NULL);
	while (i < height)
	{
		matrix[i] = (int *)malloc(sizeof(int) * width);
		if (!matrix[i])
		{
			while (i >= 0)
				free(matrix[i--]);
			free(matrix);
			return (NULL);
		}
		i++;
	}
	return (matrix);
}

void	free_matrix(int **matrix, int height)
{
	int	i;
	
	i = 0;
	while (i < height)
		free(matrix[i++]);
	free(matrix);
}

int	fill_matrix_row(char *line, int *row, int width)
{
	char	**split;
	int		i;
	
	i = 0;
	split = ft_split(line, ' ');
	if (!split)
		return (0);
	while (split[i])
	{
		row[i] = ft_atoi(split[i]);
		free(split[i++]);
	}
	free(split);
	return (1);
}

int	parse_file(char *filename, t_map *map)
{
	int		fd;
	char	*line;
	int		i;
	
	i = 0;
	fd = open(filename, O_RDONLY);
	line = NULL;
	map->height = 0;
	map->width = -1;
	map->matrix = NULL;
	while (line = get_next_line(fd))
	{
		if (map->width == -1)
			map->width = ft_wordcount(line, ' ');
		map->height++;
		free(line);
	}
	close(fd);
	fd = open(filename, O_RDONLY);
	map->matrix = alloc_matrix(map->width, map->height);
	while (i < map->height && line = get_next_line(fd))
	{
		if (!fill_matrix_row(line, map->matrix[i], map->width))
			return (free(line), 0);
		free(line);
		i++;
	}
	close(fd);
	return (1);
}

