/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:56:13 by olthorel          #+#    #+#             */
/*   Updated: 2024/11/12 16:23:10 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int nb);
int	ft_putunsigned(unsigned int nb);
int	ft_puthexa(unsigned int nb, char format);
int	ft_putptrhexa(unsigned long long addr);
int	ft_putptr(void *ptr);

int	parse(va_list args, char specifier);
int	ft_printf(const char *format, ...);

#endif
