/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:20:36 by olthorel          #+#    #+#             */
/*   Updated: 2025/01/05 16:20:36 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

float	absolute(float nbr)
{
	if (nbr < 0)
		return (-nbr);
	else
		return (nbr);
}

float	max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	min(float a, float b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

size_t	ft_split_count(const char *s, char c)
{
	size_t	i;
	size_t	counter;
	int		in_word;

	if (!s)
		return (0);
	i = 0;
	counter = 0;
	in_word = 0;
	while (s[i])
	{
		if (s[i] != c && in_word == 0)
		{
			in_word = 1;
			counter++;
		}
		else if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (counter);
}
