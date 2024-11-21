/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:45:44 by thomvan-          #+#    #+#             */
/*   Updated: 2023/12/04 17:25:36 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ucounter(unsigned int n)
{
	int	i;

	i = 0;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	i++;
	return (i);
}

static int	ft_uput(unsigned int n)
{
	if (n > 9)
		ft_putnbr((n / 10));
	ft_putchar(n % 10 + '0');
	return (ft_ucounter(n));
}

int	ft_putun(unsigned int n)
{
	ft_uput(n);
	return (ft_ucounter(n));
}
