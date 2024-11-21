/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 21:21:54 by thomvan-          #+#    #+#             */
/*   Updated: 2024/07/31 16:30:48 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/includes/libft.h"
#include "libft/includes/ft_printf.h"

#define ONE SIGUSR2
#define ZERO SIGUSR1

static void	handler(int s, siginfo_t *info, void *context)
{
	static int		i = 0;
	static char		c = 0;

	context = 0;
	info = 0;
	c = c | (s == ONE);
	i++;
	if (i == 8)
	{
		i = 0;
		ft_printf("%c", c);
		c = 0;
	}
	else
		c = c << 1;
}

int	main(void)
{
	struct sigaction	s_action;

	ft_printf("Server PID = %d\n", getpid());
	s_action.sa_sigaction = handler;
	s_action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR2, &s_action, 0);
	sigaction(SIGUSR1, &s_action, 0);
	while (1)
		pause();
	return (0);
}
