/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucieutat <cieutatulin@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:17:03 by ucieutat          #+#    #+#             */
/*   Updated: 2021/11/24 18:50:49 by ucieutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
}

void	ft_putnbr(int n)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		nb %= 10;
	}
	ft_putchar(nb + 48);
}

void	ft_puthex(uint64_t u, char *base)
{
	uint64_t i;

	i = 0;
	while (base[i])
		i++;
	if (u > i - 1)
	{
		ft_puthex(u / i, base);
		u %= i;
	}
	ft_putchar(base[u]);
}

void	ft_putptr(va_list ap)
{
	uint64_t	u;

	u = va_arg(ap, uint64_t);
	write(1, "0x", 2);
	ft_puthex(u, "0123456789abcdef");
}
