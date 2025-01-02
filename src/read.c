/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:53:26 by olthorel          #+#    #+#             */
/*   Updated: 2024/12/31 15:53:26 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_ft_split(char **tab)
{
	int i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	count_columns(char *line)
{
	int count = 0;
	int i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && (i == 0 || line[i - 1] == ' '))
			count++;
		i++;
	}
	return (count);
}

int init_map_memory(t_fdf *mlx, int height, int width)
{
    int i;

    ft_printf("Initializing map memory: height=%d, width=%d\n", height, width);
    mlx->map = malloc(sizeof(t_point *) * height);
    if (!mlx->map)
    {
        ft_printf("Failed to allocate memory for rows\n");
        return (1);
    }
    i = 0;
    while (i < height)
    {
        mlx->map[i] = malloc(sizeof(t_point) * width);
        if (!mlx->map[i])
        {
            ft_printf("Failed to allocate memory for row %d\n", i);
            while (i >= 0)
            {
                free(mlx->map[i]);
                i--;
            }
            free(mlx->map);
            return (1);
        }
        i++;
    }
    return (0);
}

int fill_map(t_fdf *mlx, char *file)
{
    int fd;
    char *line;
    char **tab;
    int i = 0;
    int j;

    ft_printf("Filling map from file: %s\n", file);
    fd = open(file, O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }

    line = get_next_line(fd);
    while (line != NULL)
    {
        ft_printf("Reading line: %s", line);
        tab = ft_split(line, ' ');
        if (!tab)
        {
            ft_printf("Failed to split line: %s\n", line);
            free(line);
            close(fd);
            return (1);
        }
        j = 0;
        while (tab[j])
        {
            if (j >= mlx->width)
            {
                ft_printf("Column count mismatch on line %d\n", i);
                free_ft_split(tab);
                free(line);
                close(fd);
                return (1);
            }
            mlx->map[i][j].x = j * 50;
            mlx->map[i][j].y = i * 50;
            mlx->map[i][j].z = ft_atoi(tab[j]);
            ft_printf("Filled point at [%d][%d]: x=%d, y=%d, z=%d\n", i, j, mlx->map[i][j].x, mlx->map[i][j].y, mlx->map[i][j].z);
            free(tab[j]);
            j++;
        }
        if (j != mlx->width)
            ft_printf("Warning: Expected %d columns, found %d on line %d\n", mlx->width, j, i);
        free(tab);
        free(line);
        line = get_next_line(fd);
        i++;
    }
    close(fd);
    return (0);
}


int	read_map(char *file, t_fdf *mlx)
{
	int     fd;
	char    *line;
	int     height = 0;
	int     width = 0;

	ft_printf("Reading map file: %s\n", file);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}

	line = get_next_line(fd);
	while (line != NULL)
	{
		ft_printf("Reading line: %s", line);
		if (height == 0)
			width = count_columns(line);
		free(line);
		height++;
		line = get_next_line(fd);
	}
	close(fd);

	ft_printf("Map dimensions: height=%d, width=%d\n", height, width);
	mlx->height = height;
	mlx->width = width;
	if (init_map_memory(mlx, height, width) != 0)
		return (1);
	if (fill_map(mlx, file) != 0)
		return (1);
	return (0);
}
