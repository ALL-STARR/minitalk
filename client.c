/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 20:39:12 by thomvan-          #+#    #+#             */
/*   Updated: 2024/07/31 16:20:30 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/includes/libft.h"
#include "libft/includes/ft_printf.h"

#define ONE SIGUSR2
#define ZERO SIGUSR1

static void	ft_transfer(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 7;
		c = *str++;
		while (i >= 0)
		{
			if ((c >> i) & 1)
				kill(pid, ONE);
			else
				kill(pid, ZERO);
			usleep(50);
			i--;
		}
	}
}

int	main(int arc, char **arv)
{
	if (arc != 3 || !arv[2] || !arv[1])
		return (1);
	ft_transfer(ft_atoi(arv[1]), arv[2]);
	return (0);
}
