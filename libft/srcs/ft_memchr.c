/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:26:07 by olthorel          #+#    #+#             */
/*   Updated: 2024/11/26 16:12:05 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		d;
	const unsigned char	*mem;

	i = 0;
	d = (unsigned char)c;
	mem = (const unsigned char *)s;
	while (i < n)
	{
		if (mem[i] == d)
			return ((void *)&mem[i]);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char	str[] = "Hello world !";
	char		ch = 'w';
	size_t		len = 13;
	char		*result = (char *)ft_memchr(str, ch, len);

	if (result != NULL)
		printf("Char '%c' found at : %ld\n", ch, result - str);
	else
		printf("Char '%c' not found", ch);
}*/
