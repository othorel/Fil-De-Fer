/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:57:28 by olthorel          #+#    #+#             */
/*   Updated: 2024/12/13 17:41:20 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int 	close_mlx(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}

int 	render(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	draw_matrix2(fdf);
	return (0);
}

void	init_fdf(t_fdf *fdf)
{
	fdf->width = WIDTH;
	fdf->height = HEIGHT;
	fdf->img.width = fdf->width;
	fdf->img.height = fdf->height - 128;
	fdf->img.pos.x = 0;
	fdf->img.pos.y = 0;
	fdf->mouse.x = 0;
	fdf->mouse.y = 0;
	fdf->mouse_right = 0;
	fdf->mouse_left = 0;
	fdf->mouse_down = 0;
	fdf->matrix.t_x = 250;
	fdf->matrix.t_y = 250;
	fdf->matrix.scale = 6;
	fdf->matrix.rot_x = 0;
	fdf->matrix.rot_y = 0;
	fdf->matrix.rot_z = 0;
	fdf->matrix.color = 0xFFFFFF;
	fdf->matrix.plus_z = 0.2;
	set_dimetric(fdf);
	
}

char *check_map_file(int ac, char **av, t_fdf *fdf)
{
	int	fd;
	
	if (ac != 2)
	{
		ft_printf("Usage: ./fdf <map.fdf>\n");
		exit(EXIT_FAILURE);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0 || read(fd, 0, 0) < 0)
	{
		ft_printf("Can't read file : ");
		ft_printf("%s", av[1]);
		ft_printf("\n");
		exit(EXIT_FAILURE);
	}
	fdf->filename = av[1];
	return (av[1]);
}

int	main(int ac, char **av)
{
	t_fdf	fdf;
	
	init_fdf(&fdf);
	parse_matrix(check_map_file(ac, av, &fdf), fdf.matrix.matrix3D);
	fdf.mlx = mlx_init();
	if (!fdf.mlx)
		exit(EXIT_FAILURE);
	fdf.win = mlx_new_window(fdf.mlx, fdf.width, fdf.height, "FDF");
	if (!fdf.win)
		exit(EXIT_FAILURE);
	fdf.img.img = mlx_new_image(fdf.mlx, fdf.img.width, fdf.img.height);
	if (!fdf.img.img)
		exit(EXIT_FAILURE);
	fdf.img.buffer = mlx_get_data_addr(fdf.img.img, &fdf.img.bits_per_pixel, &fdf.img.bits_per_line, &fdf.img.endian);
	fdf.matrix.matrix2D = alloc_map2D(fdf.matrix.matrix3D);
	draw_order(&fdf);
	render(&fdf);
	mlx_loop_hook(fdf.mlx, render, &fdf);
	mlx_key_hook(fdf.win, deal_key, &fdf);
	mlx_hook(fdf.win, ON_DESTROY, 0L, close_mlx, &fdf);
	mlx_hook(fdf.win, ON_MOTION_NOTIFY, 0L, move_mouse, &fdf);
	mlx_hook(fdf.win, ON_BUTTON_PRESS, 0L, push_mouse, &fdf);
	mlx_hook(fdf.win, ON_BUTTON_RELEASE, 0L, release_mouse, &fdf);
	mlx_loop(fdf.mlx);
}
