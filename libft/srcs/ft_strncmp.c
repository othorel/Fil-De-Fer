/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:47:14 by olthorel          #+#    #+#             */
/*   Updated: 2024/11/26 16:13:40 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] == '\0' || s2[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	str1[] = "Hello world !";
	char	str2[] = "Hello world !";
	char	str3[] = "Hello";
	char	str4[] = "Hello";
	char	str5[] = "Hello all !";

	//Test identic str
	printf("Test 1 - Identic str: \n");
	printf("ft_strncmp : %d\n", ft_strncmp(str1, str2, 13));
	printf("strncmp    : %d\n", strncmp(str1, str2, 13));

	//Test different str with n = 5
	printf("Test 2 - Differen str (n = 5): \n");
	printf("ft_strncmp : %d\n", ft_strncmp(str1, str3, 5));
	printf("strncmp    : %d\n", strncmp(str1, str3, 5));

	//Test first str is short second str n = 10
	printf("Test 3 - First str is short second str (n = 10): \n");
	printf("ft_strncmp : %d\n", ft_strncmp(str1, str5, 10));
	printf("strncmp    : %d\n", strncmp(str1, str5, 10));

	// Test case 4: Case-sensitive comparison (n = 5)
    printf("Test 4 - Case-sensitive comparison: \n");
    printf("ft_strncmp: %d\n", ft_strncmp(str3, str4, 5));
    printf("strncmp   : %d\n", strncmp(str3, str4, 5));

    // Test case 5: Compare up to a null terminator (n = 100)
    printf("Test 5 - Compare up to null terminator (n = 100): \n");
    printf("ft_strncmp: %d\n", ft_strncmp(str1, str3, 100));
    printf("strncmp   : %d\n", strncmp(str1, str3, 100));
}*/
