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

void apply_isometric_projection(t_point *p, int scale, int offset_x, int offset_y)
{
    ft_printf("Avant projection : x=%d, y=%d, z=%d\n", p->x, p->y, p->z);

    // Calcul de la projection isométrique classique
    int x_isometric = (p->x - p->y) * cos(0.5235987756);  // cos(30°) (pi/6)
    int y_isometric = (p->x + p->y) * sin(0.5235987756) - p->z; // sin(30°) (pi/6)


    // Affichage des valeurs avant l'échelle et le décalage
    ft_printf("Avant échelle : x_isometric=%d, y_isometric=%d\n", x_isometric, y_isometric);

    // Appliquer l'échelle : On multiplie par un facteur d'échelle directement sans diviser par 10
    if (scale > 1) {
        x_isometric *= scale;  // Ajuster l'échelle
        y_isometric *= scale;
    }

    // Ajouter le décalage
    int x_final = x_isometric + offset_x;
    int y_final = y_isometric + offset_y;

    ft_printf("Coordonnées avant dessin : x_final=%d, y_final=%d\n", x_final, y_final);

    // Appliquer les coordonnées finales
    p->x = x_final;
    p->y = y_final;

    // Afficher après le calcul final pour le contrôle
    ft_printf("Après projection isométrique : x=%d, y=%d\n", p->x, p->y);
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
