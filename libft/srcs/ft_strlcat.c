/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:48:48 by olthorel          #+#    #+#             */
/*   Updated: 2024/11/26 16:13:20 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	i;
	size_t	j;

	dst_len = ft_strlen(dst);
	j = 0;
	while (dst[j])
		j++;
	i = 0;
	while (src[i] && (i + j +1) < size)
	{
		dst[i + j] = src[i];
		i++;
	}
	if (i < size)
		dst[i + j] = '\0';
	if (size <= dst_len)
		return (ft_strlen(src) + size);
	else
		return (ft_strlen(src) + dst_len);
}
/*
int	main(void)
{
	char	src[] = " world !";
	char	dst[20] = "Hello";
	size_t	result;

	result = ft_strlcat(dst, src, 3); //size < dst_len
	printf("Test 1 : dst = %s result = %zu\n", dst, result);

	result = ft_strlcat(dst, src, 6); //size = dst_len
	printf("Test 2 : dst = %s result = %zu\n", dst, result);

	result = ft_strlcat(dst, src, 20); //size ok pour cat
	printf("Test 3 : dst = %s result = %zu\n", dst, result);

	char	dst2[12] = "Hello";
	result = ft_strlcat(dst2, src, 12); //size limit
	printf("Test 4 : dst = %s result = %zu\n", dst2, result);
}*/
