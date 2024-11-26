/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:35:45 by olthorel          #+#    #+#             */
/*   Updated: 2024/11/26 16:09:26 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return (ft_putstr("(null)"));
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	int	len;

	len = 0;
	if (nb == -2147483648)
		return (ft_putstr("-2147483648"));
	if (nb < 0)
	{
		len = len + ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
		len = len + ft_putnbr(nb / 10);
	len = len + ft_putchar(nb % 10 + 48);
	return (len);
}

int	ft_putunsigned(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb > 9)
		len = len + ft_putunsigned(nb / 10);
	len = len + ft_putchar(nb % 10 + 48);
	return (len);
}

int	ft_puthexa(unsigned int nb, char format)
{
	char	*base;
	int		len;

	len = 0;
	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nb >= 16)
		len = len + ft_puthexa(nb / 16, format);
	len = len + ft_putchar(base[nb % 16]);
	return (len);
}
