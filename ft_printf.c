/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucieutat <cieutatulin@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:39:27 by ucieutat          #+#    #+#             */
/*   Updated: 2021/12/01 17:22:17 by ucieutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	which_flag(char c, va_list ap)
{
	if (c == 'c')
		return (ft_putchar((char)va_arg(ap, int)));
	else if (c == 's')
		return (ft_putstr((char *)va_arg(ap, char *)));
	else if (c == 'p')
		return (ft_putptr(va_arg(ap, uint64_t)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (c == 'u')
		return (ft_puthex(va_arg(ap, unsigned int), "0123456789"));
	else if (c == 'x')
		return (ft_puthex(va_arg(ap, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_puthex(va_arg(ap, unsigned int), "0123456789ABCDEF"));
	else if (c == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	else
		return (-1);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		count;

	va_start(ap, str);
	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			count += which_flag(str[i + 1], ap);
			if (count == -1)
				return (-1);
			i++;
		}
		else
		{
			if (write(1, &str[i], 1) == -1)
				return (-1);
			count++;
		}
	}
	va_end(ap);
	return (count);
}
