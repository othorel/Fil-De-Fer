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
	if (fdf)
		render(fdf);
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
	int		fd;
	t_fdf	*fdf;

	if (argc != 2)
		error(1);
	file_name = argv[1];
	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		error(2);
	fdf = init_fdf(file_name);
	if (!fdf)
		error(1);
	render(fdf);
	mlx_hook(fdf->win, 2, 1L << 0, &key_handle, fdf);
	mlx_hook(fdf->win, 17, 0L, &handle_destroy, fdf);
	mlx_loop_hook(fdf->mlx, &expose_handle, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
