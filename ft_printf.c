/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucieutat <cieutatulin@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:39:27 by ucieutat          #+#    #+#             */
/*   Updated: 2021/11/25 01:18:42 by ucieutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"


int	which_flag(char c, va_list ap)
{
	if (c == 'c')
		ft_putchar((char)va_arg(ap, int));
	else if (c == 's')
		ft_putstr((char *)va_arg(ap, char *));
	else if (c == 'p')
	{
		write(1, "0x", 2);
		ft_puthex(va_arg(ap, uint64_t), "0123456789abcdef");
	}
	else if (c == 'd')
		ft_putnbr(va_arg(ap, int));
	else if (c == 'i')
		ft_putnbr(va_arg(ap, int));
	else if (c == 'u')
		ft_puthex(va_arg(ap, unsigned int), "0123456789");
	else if (c == 'x')
		ft_puthex(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		ft_puthex(va_arg(ap, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		write(1, "%", 1);
	else
		return (0);
	return (1);
}

int		ft_printf(char *str, ...)
{
	va_list	ap;
	int		i;
	int		flag;
	
	va_start(ap, str);
	i = -1;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			flag = which_flag(str[i+1], ap);
			if (!flag)
				return (0);
			i++;
		}
		else
			write(1, &str[i], 1);
	}
	va_end(ap);
	return (1);
}

int main()
{
	char t;
	char s[6] = "coucou";
	int	d;

	t = 'r';
	d = 122;
	printf("%s on est le %X octobre et la lettre du %% jour est : %c\n", s, d, t);
	ft_printf("%s on est le %X octobre et la lettre %%  du jour est : %c\n", s, d, t);
}
