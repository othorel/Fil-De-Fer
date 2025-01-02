/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:12:26 by olthorel          #+#    #+#             */
/*   Updated: 2024/12/31 15:12:26 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void clean_up(t_fdf *mlx, t_fdf *win)
{
    if (win) {
        mlx_destroy_window(mlx, win);  // Détruire la fenêtre
    } else {
        printf("Error: Window pointer is NULL.\n");
    }

    if (mlx) {
        mlx_destroy_display(mlx);  // Détruire la connexion à la display
        free(mlx);  // Libérer la mémoire allouée
    } else {
        printf("Error: mlx pointer is NULL.\n");
    }
}

int close_windows(void *param)
{
    t_fdf *map = (t_fdf *)param;

    if (!map || !map->mlx || !map->win)
    {
        ft_printf("Erreur: tentative de fermeture avec des pointeurs NULL\n");
        exit(1);
    }
    ft_printf("<<<< Closed window >>>>\n");
    clean_up(map->mlx, map->win);
    exit(0);
    return (0); // Forme standard, mais exit() arrête déjà tout
}

int key_hook(int key, void *param)
{
    t_fdf **map;
    
    map = (t_fdf **)param;
    if (key == 65307) // Touche ESC
    {
        ft_printf("<<<< Closed window >>>>\n");
        if (!map || !map[0] || !map[1])
        {
            ft_printf("Erreur: tentative de fermeture avec des pointeurs NULL\n");
            exit(1);
        }
        clean_up(map[0], map[1]);
        exit(0);
    }
    return (0);
}
