/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:07:23 by olthorel          #+#    #+#             */
/*   Updated: 2024/11/26 16:12:26 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*mem;
	unsigned char	d;

	i = 0;
	mem = (unsigned char *)s;
	d = (unsigned char)c;
	while (i < n)
	{
		mem[i] = d;
		i++;
	}
	return (s);
}
/*
int	main(void)
{
	char	str[20];
	size_t	i = 0;

	strcpy(str, "Hello world !");
	printf("Before memset: %s\n", str);
	ft_memset(str, '*', 5);
	printf("After memset : ");

	while (i < 20)
	{
		printf("%c", str[i]);
		i++;
	}
	printf("\n");
}*/
