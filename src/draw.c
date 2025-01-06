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

    dx = fabs(end.x - start.x);
    dy = fabs(end.y - start.y);
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

// void draw_grid(void *mlx, void *win, int color)
// {
//     t_point p1;
//     t_point p2;
//     int y;
//     int x;

//     y = 50;
//     while (y <= 950)
//     {
//         p1.x = 50;
//         p1.y = y;
//         p2.x = 1950;
//         p2.y = y;
//         draw_line(mlx, win, p1, p2, color);
//         y += 50;
//     }
//     x = 50;
//     while (x <= 1950)
//     {
//         p1.x = x;
//         p1.y = 50;
//         p2.x = x;
//         p2.y = 950;
//         draw_line(mlx, win, p1, p2, color);
//         x += 50;
//     }
// }


int calculate_scale(int width, int height, int win_width, int win_height)
{
    int scale_x;
    int scale_y;
    int scale;

    scale_x = win_width / width;
    scale_y = win_height / height;
    if (scale_x < scale_y)
        scale = scale_x;
    else
        scale = scale_y;
    return (scale);
}

void draw_map(void *mlx, void *win, t_fdf *data)
{
    int x;
    int y;
    int color;
    int scale;
    int offset_x;
    int offset_y;

    // Calcul dynamique du facteur d'échelle et des décalages
    scale = calculate_scale(data->width, data->height, WIN_WIDTH, WIN_HEIGHT); // Ajusté pour la projection isométrique
    offset_x = (WIN_WIDTH - (data->width * scale)) / 2;
    offset_y = (WIN_HEIGHT - (data->height * scale)) / 2;

    ft_printf("Starting to draw map...\n");

    y = 0;
    while (y < data->height)
    {
        x = 0;
        while (x < data->width)
        {
            // Afficher les coordonnées avant la projection
            ft_printf("Before drawing point: (%d, %d, %d)\n", data->map[y][x].x, data->map[y][x].y, data->map[y][x].z);

            // Appliquer la projection isométrique (en prenant en compte l'échelle et le décalage)
            apply_isometric_projection(&data->map[y][x], scale, offset_x, offset_y);

            // Définir la couleur en fonction de la hauteur (z)
            color = get_color_by_z(data->map[y][x].z);

            // Dessiner le point après la projection et application de l'échelle et du décalage
            if (data->map[y][x].x >= 0 && data->map[y][x].x < WIN_WIDTH &&
                data->map[y][x].y >= 0 && data->map[y][x].y < WIN_HEIGHT)
            {
                ft_printf("Drawing point at (%d, %d) with color: %d\n", data->map[y][x].x, data->map[y][x].y, color);
                mlx_pixel_put(mlx, win, data->map[y][x].x, data->map[y][x].y, color);
            }

            // Relier aux voisins (droite et bas)
            if (x < data->width - 1)
                draw_line(mlx, win, data->map[y][x], data->map[y][x + 1], color);
            if (y < data->height - 1)
                draw_line(mlx, win, data->map[y][x], data->map[y + 1][x], color);

            x++;
        }
        y++;
    }
}

