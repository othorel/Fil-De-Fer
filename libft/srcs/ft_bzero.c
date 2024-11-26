/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:16:07 by olthorel          #+#    #+#             */
/*   Updated: 2024/11/26 16:10:15 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*mem;

	i = 0;
	mem = (unsigned char *)s;
	while (i < n)
	{
		mem[i] = 0;
		i++;
	}
}
/*
int	main(void)
{
	char	buffer[10];
	size_t	i = 0;

	memset(buffer, '1', sizeof(buffer));
	printf("Before Bzero: ");
	while (i < sizeof(buffer))
	{
		printf("%c ", buffer[i]);
		i++;
	}
	printf("\n");
	ft_bzero(buffer, 5);
	i = 0;
	printf("After Bzero : ");
	while (i < sizeof(buffer))
	{
		if (buffer[i] == 0)
			printf("0 ");
		else
			printf("%c ", buffer[i]);
		i++;
	}
	printf("\n");
}*/
