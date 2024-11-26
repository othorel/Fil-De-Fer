/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:13:51 by olthorel          #+#    #+#             */
/*   Updated: 2024/11/26 16:13:25 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (size != 0)
	{
		while (src[i] && i < size -1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}
/*
int	main(void)
{
	char	src[] = "Hello world !";
	char	dst[20];
	size_t	size = 6;
	size_t	src_len = ft_strlcpy(dst, src, size);

	printf("Src : %s\n", src);
	printf("Dst : %s\n", dst);
	printf("Len of src : %zu\n", src_len);
	printf("Size copy  : %zu\n", strlen(dst));
}*/
