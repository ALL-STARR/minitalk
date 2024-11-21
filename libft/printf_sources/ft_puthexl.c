/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:21:46 by thomvan-          #+#    #+#             */
/*   Updated: 2023/12/14 16:05:54 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_counter(unsigned long n)
{
	int	i;

	i = 0;
	while (n >= 16)
	{
		n /= 16;
		i++;
	}
	i++;
	return (i);
}

static void	ft_puth(unsigned long nbr, const char *base)
{
	if (nbr >= 16)
		ft_puth(nbr / 16, base);
	ft_putchar(base[nbr % 16]);
}

int	ft_puthexl(unsigned long nbr, const char *base)
{
	ft_puth(nbr, base);
	return (ft_hex_counter(nbr));
}
