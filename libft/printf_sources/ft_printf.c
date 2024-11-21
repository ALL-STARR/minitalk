/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:49:53 by thomvan-          #+#    #+#             */
/*   Updated: 2023/12/14 16:41:20 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_printer(va_list arg, const char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(arg, int)));
	if (c == 's')
		return (ft_putstr(va_arg(arg, char *)));
	if (c == 'i' || c == 'd')
		return (ft_putnbr(va_arg(arg, int)));
	if (c == '%')
		return (ft_putchar('%'));
	if (c == 'p')
	{
		write(1, "0x", 2);
		return (ft_puthexl(va_arg(arg, unsigned long), "0123456789abcdef") + 2);
	}
	if (c == 'x')
		return (ft_puthex(va_arg(arg, unsigned int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_puthex(va_arg(arg, unsigned int), "0123456789ABCDEF"));
	if (c == 'u')
		return (ft_putun(va_arg(arg, unsigned int)));
	else
		return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		len;

	len = 0;
	i = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%' && ft_strchr("cspdiuxX%", str[i + 1]))
		{
			len += ft_printer(ap, str[i + 1]);
			i++;
		}
		else
		{
			ft_putchar(str[i]);
			len++;
		}
		i++;
	}
	va_end(ap);
	return (len);
}
