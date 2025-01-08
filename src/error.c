/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:12:26 by olthorel          #+#    #+#             */
/*   Updated: 2024/12/31 15:12:26 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	error(int exit_code)
{
	if (exit_code == 0)
		ft_printf("FDF closed.\n");
	else if (exit_code == 1)
		ft_printf("Wrong usage -> ./fdf [map.fdf]\n");
	else if (exit_code == 2)
		ft_printf("Cannot read file.\n");
	else if (exit_code == 3)
		ft_printf("Cannot init fdf.\n");
	else if (exit_code == 4)
		ft_printf("Cannot parse map.\n");
	else if (exit_code == 5)
		ft_printf("Cannot create image.\n");
	else if (exit_code == 6)
		ft_printf("Cannot init cam.\n");
	else if (exit_code == 7)
		ft_printf("Unable to render.\n");
	else if (exit_code == 8)
		ft_printf("Cannot init color.\n");
	exit(exit_code);
}
