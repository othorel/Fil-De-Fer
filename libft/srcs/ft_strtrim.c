/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:47:13 by olthorel          #+#    #+#             */
/*   Updated: 2024/11/26 16:13:58 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	is_in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*trim;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && is_in_set(s1[end - 1], set))
		end--;
	len = end - start;
	trim = (char *)malloc(sizeof(char) * (len + 1));
	if (!trim)
		return (NULL);
	ft_strlcpy(trim, &s1[start], len + 1);
	return (trim);
}
/*
int	main(void)
{
	char	*result;

	result = ft_strtrim("   Hello world    ", " ");
	printf("Trim : '%s'\n", result);
	free(result);

	result = ft_strtrim("xxxHello worldxxx", "x");
	printf("Trim : '%s'\n", result);
	free(result);

	result = ft_strtrim("xxxxxx", "x");
	printf("Trim : '%s'\n", result);
	free(result);

	result = ft_strtrim("Hello world", "x");
	printf("Trim : '%s'\n", result);
	free(result);

	result = ft_strtrim(NULL, "x");

	if (!result)
		printf("Return Null\n");

}*/
