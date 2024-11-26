/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:43:16 by olthorel          #+#    #+#             */
/*   Updated: 2024/11/26 16:13:46 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n_len;

	if (ft_strlen(little) == 0)
		return ((char *)big);
	n_len = ft_strlen(little);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] && big[i + j] == little[j] && i + j < len)
			j++;
		if (j == n_len)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	 // Cas où 'little' est trouvé au début de 'big'
    const char *big = "Hello, world!";
    const char *little = "Hello";
    size_t len = 12;
    char *result = ft_strnstr(big, little, len);	
    printf("Test 1 - Expected: %s, Got: %s\n", big, result);

    // Cas où 'little' est au milieu de 'big'
    big = "Hello, world!";
    little = "world";
    len = 12;
    result = ft_strnstr(big, little, len);
    printf("Test 2 - Expected: world!, Got: %s\n", result);

    // Cas où 'little' est plus long que 'len'
    big = "Hello, world!";
    little = "world";
    len = 5;
    result = ft_strnstr(big, little, len);
    printf("Test 3 - Expected: (null), Got: %s\n", result ? result : "(null)");

    // Cas où 'little' n'est pas dans 'big'
    big = "Hello, world!";
    little = "planet";
    len = 12;
    result = ft_strnstr(big, little, len);
    printf("Test 4 - Expected: (null), Got: %s\n", result ? result : "(null)");

    // Cas où 'little' est une chaîne vide
    big = "Hello, world!";
    little = "";
    len = 12;
    result = ft_strnstr(big, little, len);
    printf("Test 5 - Expected: %s, Got: %s\n", big, result);

    // Cas où 'big' est une chaîne vide et 'little' n'est pas vide
    big = "";
    little = "test";
    len = 5;
    result = ft_strnstr(big, little, len);
    printf("Test 6 - Expected: (null), Got: %s\n", result ? result : "(null)");
}*/
