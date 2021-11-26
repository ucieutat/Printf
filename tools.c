/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucieutat <cieutatulin@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:17:03 by ucieutat          #+#    #+#             */
/*   Updated: 2021/11/26 12:53:38 by ucieutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (write(1, s, i));
}

int	ft_putnbr(int n)
{
	long			nb;
	static int		count;

	nb = n;
	count = 0;
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
	count++;
	return (count + (n < 0));
}

int	ft_puthex(uint64_t u, char *base)
{
	uint64_t	i;
	static int	count;

	i = 0;
	count = 0;
	while (base[i])
		i++;
	if (u > i - 1)
	{
		ft_puthex(u / i, base);
		u %= i;
	}
	ft_putchar(base[u]);
	count++;
	return (count);
}

int	ft_putptr(uint64_t u)
{
	int count;

	count = 0;
	if (u)
	{
		write(1, "0x", 2);
		count = ft_puthex(u, "0123456789abcdef") + 2;
	}
	else
		count = ft_putstr("(nil)");
	return (count);
}
