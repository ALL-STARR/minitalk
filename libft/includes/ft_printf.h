/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:28:59 by thomvan-          #+#    #+#             */
/*   Updated: 2023/12/14 16:04:45 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_puthex(unsigned int nbr, const char *base);
int		ft_putun(unsigned int n);
int		ft_puthexl(unsigned long nbr, const char *base);
int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putstr(char *s);
char	*ft_strchr(const char *s, int c);

#endif