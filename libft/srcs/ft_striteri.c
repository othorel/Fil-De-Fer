/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:26:37 by olthorel          #+#    #+#             */
/*   Updated: 2024/11/26 16:13:12 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, s + i);
		i++;
	}
}
/*
static void	test_function(unsigned int index, char *c) 
{
    printf("Index: %u -> Character: %c\n", index, *c);
}

int	main(void)
{
	char	str[] = "Hello";

	printf("Test : Str 'Hello'\n");
	ft_striteri(str, test_function);
}*/
