/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:13:23 by olthorel          #+#    #+#             */
/*   Updated: 2024/12/31 15:13:23 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void draw_line(void *mlx, void *win, t_point start, t_point end, int color)
{
    int dx;
    int dy;
    int sx;
    int sy;
    int err;
    int e2;

    dx = abs(end.x - start.x);
    dy = abs(end.y - start.y);
    err = dx - dy;

    if (start.x < end.x)
        sx = 1;
    else
        sx = -1;
    if (start.y < end.y)
        sy = 1;
    else
        sy = -1;

    while (1)
    {
        // Vérification des coordonnées avant de dessiner
        if (start.x >= 0 && start.x < WIN_WIDTH && start.y >= 0 && start.y < WIN_HEIGHT)
        {
            mlx_pixel_put(mlx, win, start.x, start.y, color);
        }

        // Si la ligne a atteint le point final, on s'arrête
        if (start.x == end.x && start.y == end.y)
            break;

        e2 = 2 * err;

        // Déplacement sur l'axe X
        if (e2 > -dy)
        {
            err -= dy;
            start.x += sx;
        }

        // Déplacement sur l'axe Y
        if (e2 < dx)
        {
            err += dx;
            start.y += sy;
        }
    }
}

void draw_grid(void *mlx, void *win, int color)
{
    t_point p1;
    t_point p2;
    int y;
    int x;

    y = 50;
    while (y <= 950)
    {
        p1.x = 50;
        p1.y = y;
        p2.x = 1950;
        p2.y = y;
        draw_line(mlx, win, p1, p2, color);
        y += 50;
    }
    x = 50;
    while (x <= 1950)
    {
        p1.x = x;
        p1.y = 50;
        p2.x = x;
        p2.y = 950;
        draw_line(mlx, win, p1, p2, color);
        x += 50;
    }
}

void draw_map(void *mlx, void *win, t_fdf *data)
{
    int x;
    int y;
    int color;
    int scale = 10; // Facteur d'échelle pour ajuster la taille des points
    int offset_x = WIN_WIDTH / 2; // Décalage horizontal
    int offset_y = WIN_HEIGHT / 2; // Décalage vertical

    ft_printf("Starting to draw map...\n");
    y = 0;
    while (y < data->height)
    {
        x = 0;
        while (x < data->width)
        {
            // Affichage des coordonnées avant la projection
            ft_printf("Before drawing point: (%d, %d, %d)\n", data->map[y][x].x, data->map[y][x].y, data->map[y][x].z);

            // Appliquer la projection isométrique avec mise à l'échelle et décalage
            apply_isometric_projection(&data->map[y][x], scale, offset_x, offset_y);

            // Affichage après la projection
            ft_printf("After projection: (%d, %d)\n", data->map[y][x].x, data->map[y][x].y);

            // Définir la couleur en fonction de la hauteur
            color = get_color_by_z(data->map[y][x].z);

            // Dessiner le point
            mlx_pixel_put(mlx, win, data->map[y][x].x, data->map[y][x].y, color);

            // Relier le point à son voisin de droite, si ce n'est pas le dernier point de la ligne
            if (x < data->width - 1)
                draw_line(mlx, win, data->map[y][x], data->map[y][x + 1], color);

            // Relier le point à son voisin du bas, si ce n'est pas la dernière ligne
            if (y < data->height - 1)
                draw_line(mlx, win, data->map[y][x], data->map[y + 1][x], color);

            x++;
        }
        y++;
    }
}
