/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:39:56 by thomvan-          #+#    #+#             */
/*   Updated: 2023/12/04 17:27:52 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_counter(int n)
{
	int		i;
	long	l;

	l = (long)n;
	i = 0;
	if (l < 0)
	{
		l *= -1;
		i++;
	}
	while (l > 9)
	{
		l /= 10;
		i++;
	}
	i++;
	return (i);
}

static void	ft_put(int n)
{
	long	l;

	l = (long)n;
	if (l < 0)
	{
		l *= -1;
		ft_putchar('-');
	}
	if (l > 9)
		ft_putnbr((l / 10));
	ft_putchar(l % 10 + '0');
	return ;
}

int	ft_putnbr(int n)
{
	ft_put(n);
	return (ft_counter(n));
}
