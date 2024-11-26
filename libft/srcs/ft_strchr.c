/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:18:52 by olthorel          #+#    #+#             */
/*   Updated: 2024/11/26 16:13:04 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	d;

	i = 0;
	d = (unsigned char)c;
	while (s[i] != '\0')
	{
		if (s[i] == d)
			return ((char *)s + i);
		i++;
	}
	if (d == '\0')
		return ((char *)s + i);
	return (NULL);
}
/*
int	main(void)
{
	const char	*str = "Hello world !";
	char		ch = 'o';
	char		*result = ft_strchr(str, ch);

	if (result != NULL)
		printf("Char '%c' find at : %ld\n", ch, result - str);
	else
		printf("Char '%c' not find.\n", ch);

	ch = '\0'; //Test avec \0
	result = ft_strchr(str, ch);

	if (result != NULL)
		printf("Char '%c' find at : %ld\n", ch, result - str);
	else
		printf("Char '%c' not find.\n", ch);
}*/
