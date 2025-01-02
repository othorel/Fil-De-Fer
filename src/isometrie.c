/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometrie.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:28:02 by olthorel          #+#    #+#             */
/*   Updated: 2025/01/02 15:28:02 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

#include "../includes/fdf.h"

void apply_isometric_projection(t_point *p, int scale, int offset_x, int offset_y)
{
    int temp_x = p->x;
    int temp_y = p->y;

    // Affichage avant transformation pour déboguer
    ft_printf("Avant projection : x=%d, y=%d, z=%d\n", p->x, p->y, p->z);

    // Appliquer la projection isométrique (rotation de 30° sur X et Y)
    p->x = (temp_x - temp_y) * cos(0.523599);  // cos(30°)
    p->y = (temp_x + temp_y) * sin(0.523599) - p->z;

    // Appliquer un facteur d'échelle pour s'assurer que les points restent dans la fenêtre
    p->x = p->x * scale + offset_x;
    p->y = p->y * scale + offset_y;

    // Affichage après transformation pour déboguer
    ft_printf("Après projection : x=%d, y=%d\n", p->x, p->y);

    // Vérification si les coordonnées sont à l'intérieur de la fenêtre
    if (p->x < 0 || p->x >= WIN_WIDTH || p->y < 0 || p->y >= WIN_HEIGHT)
    {
        ft_printf("Avertissement : coordonnées hors de la fenêtre : (%d, %d)\n", p->x, p->y);
    }
}


int get_color_by_z(int z)
{
    if (z > 0)
        return 0xFF0000; // Rouge si l'altitude est positive
    else if (z < 0)
        return 0x0000FF; // Bleu si l'altitude est négative
    else
        return 0xFFFFFF; // Blanc si z = 0
}
