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

<<<<<<< HEAD
static void	isometric(t_line *line)
{
	t_point	new_start;
	t_point	new_end;

	new_start.x = (line->start.x - line->start.y) * cos(ANG_30);
	new_start.y = (line->start.x + line->start.y) * sin(ANG_30) - \
		line->start.z;
	line->start.x = new_start.x;
	line->start.y = new_start.y;
	new_end.x = (line->end.x - line->end.y) * cos(ANG_30);
	new_end.y = (line->end.x + line->end.y) * sin(ANG_30) - line->end.z;
	line->end.x = new_end.x;
	line->end.y = new_end.y;
}

static void	perspective(t_line *line)
=======
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
>>>>>>> fcb3a2d651ca1a6754058721cbbc5b38514a430c
{
	t_point	new_start;
	t_point	new_end;
	double	z;

	rotate_x(line, 3 * -ANG_45);
	z = line->start.z + line->transform_z;
	new_start.x = line->start.x / z;
	new_start.y = line->start.y / z;
	line->start.x = new_start.x;
	line->start.y = -new_start.y;
	z = line->end.z + line->transform_z;
	new_end.x = line->end.x / z;
	new_end.y = line->end.y / z;
	line->end.x = new_end.x;
	line->end.y = -new_end.y;
	scale(line, line->transform_z);
}

void	project(t_cam *cam, t_line *line)
{
	if (cam->projection == ISOMETRIC)
		isometric(line);
	else if (cam->projection == PERSPECTIVE)
		perspective(line);
	else if (cam->projection == TOP)
		return ;
}
