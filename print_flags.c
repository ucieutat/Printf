/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucieutat <cieutatulin@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:44:15 by ucieutat          #+#    #+#             */
/*   Updated: 2021/11/24 18:50:50 by ucieutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_char(char c)
{
	write(1, &c, 1);
}

void	print_string(va_list ap)
{
	char	*s;
	int		i;

	s = va_arg(ap, char *);
	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
}

void	print_digit(va_list ap)
{
	int	d;

	d = va_arg(ap, int);
	ft_putnbr(d);
}

void	print_unsigned(va_list ap)
{
	unsigned int	u;

	u = va_arg(ap, unsigned int);
	ft_puthex(u, "0123456789");
}

void	print_hex(va_list ap)
{
	unsigned int	u;

	u = va_arg(ap, unsigned int);
	ft_puthex(u, "0123456789abcdef");
}
