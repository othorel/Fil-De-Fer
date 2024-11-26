/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:51:34 by olthorel          #+#    #+#             */
/*   Updated: 2024/11/26 16:09:16 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int	ft_putptrhexa(unsigned long long addr)
{
	int					len;
	char				hexa[17];
	char				*base;
	int					i;

	len = 0;
	i = 0;
	base = "0123456789abcdef";
	if (addr == 0)
		return (ft_putchar('0'));
	while (addr > 0)
	{
		hexa[i] = base[addr % 16];
		addr = addr / 16;
		i++;
	}
	while (i > 0)
	{
		len = len + ft_putchar(hexa[i - 1]);
		i--;
	}
	return (len);
}

int	ft_putptr(void *ptr)
{
	int	len;

	if (ptr == NULL)
	{
		len = ft_putstr("(nil)");
		return (len);
	}
	len = ft_putstr("0x");
	len = len + ft_putptrhexa((unsigned long long)ptr);
	return (len);
}

int	parse(va_list args, char specifier)
{
	int	len;

	len = 0;
	if (specifier == 'c')
		len = len + ft_putchar(va_arg(args, int));
	else if (specifier == 's')
		len = len + ft_putstr(va_arg(args, char *));
	else if (specifier == 'd' || specifier == 'i')
		len = len + ft_putnbr(va_arg(args, int));
	else if (specifier == 'u')
		len = len + ft_putunsigned(va_arg(args, unsigned int));
	else if (specifier == 'x')
		len = len + ft_puthexa(va_arg(args, unsigned int), 'x');
	else if (specifier == 'X')
		len = len + ft_puthexa(va_arg(args, unsigned int), 'X');
	else if (specifier == 'p')
		len = len + ft_putptr(va_arg(args, void *));
	else if (specifier == '%')
		len = len + ft_putchar('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			len = len + parse(args, format[i + 1]);
			i++;
		}
		else
			len = len + ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
/*
int	main(void)
{
	int		c = 'a';
	char	*s = "Hello world !";
	int		i = 42;
	unsigned int u = 42;
	unsigned int x = 42;
	unsigned int y = 42;

	ft_printf("Test : c -> %c, s -> %s, i -> %d",c, s, i);
	ft_printf("u -> %u, x -> %x, y -> %X", u, x, y);
	ft_printf(" %p %p ", 0, 0);
}*/	
