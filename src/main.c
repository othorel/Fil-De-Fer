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
	if (fdf->process == 1)
		return (0);
	render(fdf);
	fdf->process = 0;
	return (0);
}

static int	handle_destroy(t_fdf *fdf)
{
	if (fdf)
		close_all(fdf, 0);
	exit(0);
}

int	main(int argc, char **argv)
{
	char	*file_name;
	t_fdf	*fdf;

	if (argc != 2)
		error(1);
	file_name = argv[1];
	fdf = init_fdf(file_name);
	if (!fdf)
		error(1);
	gettimeofday(&fdf->fps_data.last_time, NULL);
	fdf->fps_data.frames_count = 0;
	fdf->fps_data.fps = 0;
	fdf->process = 0;
	render(fdf);
	mlx_hook(fdf->win, 2, 1L << 0, &key_handle, fdf);
	mlx_hook(fdf->win, 17, 0L, &handle_destroy, fdf);
	mlx_expose_hook(fdf->win, &expose_handle, fdf);
	mlx_loop(fdf->mlx);
}
