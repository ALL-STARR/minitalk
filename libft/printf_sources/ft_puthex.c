/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:56:43 by thomvan-          #+#    #+#             */
/*   Updated: 2023/12/04 17:25:25 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_counter(unsigned int n)
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

static void	ft_puth(unsigned int nbr, const char *base)
{
	if (nbr >= 16)
		ft_puth(nbr / 16, base);
	ft_putchar(base[nbr % 16]);
}

int	ft_puthex(unsigned int nbr, const char *base)
{
	ft_puth(nbr, base);
	return (ft_hex_counter(nbr));
}
