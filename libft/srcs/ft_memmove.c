/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:56:41 by olthorel          #+#    #+#             */
/*   Updated: 2024/11/26 16:12:19 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_cpy(unsigned char *dst, unsigned char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dst_tmp;
	unsigned char	*src_tmp;

	if (!dest && !src)
		return (NULL);
	if (!n)
		return (dest);
	dst_tmp = (unsigned char *)dest;
	src_tmp = (unsigned char *)src;
	if (dst_tmp < src_tmp)
		ft_cpy(dst_tmp, src_tmp, n);
	else
	{
		while (n > 0)
		{
			n--;
			dst_tmp[n] = src_tmp[n];
		}
	}
	return (dst_tmp);
}
/*
int	main(void)
{
	unsigned char	src[] = "Hello world !";
	unsigned char	dst[20];
	unsigned char	overlap[] = "Hello world !";
	size_t			n = strlen((char *)src) + 1;

	printf("Before memmove:\n");
	printf("Src : %s\n", src);
	printf("Dst : %s\n", dst);

	ft_memmove(dst, src, n);

	printf("After memmove:\n");
	printf("Src : %s\n", src);
	printf("Dst : %s\n", dst);

	printf("Test overlap:\n");
	printf("Before test overlap:\n");
	printf("Src : %s\n", overlap);

	ft_memmove(overlap + 5, overlap, strlen((char *)overlap) + 1);

	printf("After test overlap:\n");
	printf("Src : %s\n", overlap);
}*/
