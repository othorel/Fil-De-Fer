/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:05:20 by olthorel          #+#    #+#             */
/*   Updated: 2024/12/31 15:05:20 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	expose_handle(t_fdf *fdf)
{
<<<<<<< HEAD
	render(fdf);
	return (0);
}

int	main(int argc, char **argv)
{
	char	*file_name;
	t_fdf	*fdf;

	if (argc != 2)
		error(1);
	file_name = argv[1];
	fdf = init_fdf(file_name);
	render(fdf);
	mlx_key_hook(fdf->win, &key_handle, fdf);
	mlx_expose_hook(fdf->win, &expose_handle, fdf);
	mlx_hook(fdf->win, 17, 0, handle_close, fdf);
	mlx_loop(fdf->mlx);
=======
    t_fdf mlx;

    if (ac != 2)
    {
        ft_printf("Usage: ./fdf <map.fdf>\n");
        return (1);
    }

    ft_printf("Initializing mlx...\n");
    mlx.mlx = mlx_init();
    if (!mlx.mlx)
    {
        ft_printf("Failed to initialize mlx\n");
        return (1);
    }

    ft_printf("Creating window...\n");
    mlx.win = mlx_new_window(mlx.mlx, 2000, 1000, "FDF OLTHOREL");
    if (!mlx.win)
    {
        ft_printf("Failed to create window\n");
        mlx_destroy_display(mlx.mlx);
        free(mlx.mlx);
        return (1);
    }

    ft_printf("Reading map...\n");
    if (read_map(av[1], &mlx) != 0)
    {
        ft_printf("Failed to read map\n");
        mlx_destroy_window(mlx.mlx, mlx.win);
        mlx_destroy_display(mlx.mlx);
        free(mlx.mlx);
        return (1);
    }

    ft_printf("Drawing grid...\n");
    //draw_grid(mlx.mlx, mlx.win, COLOR);

    ft_printf("Drawing map...\n");
    draw_map(mlx.mlx, mlx.win, &mlx);

    ft_printf("Setting up hooks...\n");
    mlx_hook(mlx.win, 17, 0, close_windows, &mlx);
    mlx_key_hook(mlx.win, key_hook, &mlx);

    ft_printf("Starting mlx loop...\n");
    mlx_loop(mlx.mlx);

    clean_up(&mlx, mlx.win);
    return (0); // Ce return sera atteint après que mlx_loop() soit terminé.
>>>>>>> fcb3a2d651ca1a6754058721cbbc5b38514a430c
}
