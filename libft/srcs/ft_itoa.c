/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:36:12 by olthorel          #+#    #+#             */
/*   Updated: 2024/11/26 16:10:47 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	nb_len(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
	{
		count++;
		if (n == 0)
			return (1);
	}
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static void	nb_pos(char *str, long nb, int i)
{
	while (nb > 0)
	{
		str[--i] = (nb % 10) + 48;
		nb = nb / 10;
	}
}

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	long int	nb;

	i = nb_len(n);
	nb = n;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	if (nb == 0)
	{
		str[0] = 48;
		return (str);
	}
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	nb_pos(str, nb, i);
	return (str);
}
/*
int	main(void)
{
	int	test[] = {0, 42, -42, -2147483648, 2147483647};
	int	size = 5;
	int	i = 0;

	while (i < size)
	{
		char	*result = ft_itoa(test[i]);
		printf("ft_itoa %d = %s\n", test[i], result);
		free(result);
		i++;
	}
}*/
