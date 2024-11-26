/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:28:25 by olthorel          #+#    #+#             */
/*   Updated: 2024/11/26 16:12:13 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dst_tmp;
	const unsigned char	*src_tmp;

	if (!dest && !src)
		return (dest);
	i = 0;
	dst_tmp = (unsigned char *)dest;
	src_tmp = (const unsigned char *)src;
	while (i < n)
	{
		dst_tmp[i] = src_tmp[i];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char	src[10] = "12356789";
	char	dest[10] = "000000000";

	printf("Before memcpy:\n");
	printf("src  : %s\n", src);
	printf("dest : %s\n", dest);
	ft_memcpy(dest, src, sizeof(src));
	printf("After memcpy:\n");
	printf("src  : %s\n", src);
	printf("dest : %s\n", dest);
}*/
