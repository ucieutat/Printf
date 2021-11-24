/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucieutat <cieutatulin@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:39:27 by ucieutat          #+#    #+#             */
/*   Updated: 2021/11/24 18:50:49 by ucieutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"


t_flag	which_flag(char c)
{
	if (c == 'c')
		return (print_char((char)va_arg(ap, int));
	else if (c == 's')
		return (print_string((char *)va_arg(ap, char *));
	else if (c == 'p')
		return (pointer);
	else if (c == 'd')
		return (e_digit);
	else if (c == 'i')
		return (e_int);
	else if (c == 'u')
		return (e_unsigned);
	else if (c == 'x')
		return (e_hex);
	else if (c == '%')
		return (e_percent);
	else
		return (e_other);
}

void	which_action (t_flag flag, va_list ap)
{
	if (flag == e_char)
		print_char(ap);
	else if (flag == e_string)
		print_string(ap);
	else if (flag == e_pointer)
		ft_putptr(ap);
	else if (flag == e_digit || flag == e_int)
		print_digit(ap);
	else if (flag == e_unsigned)
		print_unsigned(ap);
	else if (flag == e_hex)
		print_hex(ap);
	else if (flag == e_percent)
		write(1, "%", 1);
}

int		ft_printf(char *str, ...)
{
	va_list	ap;
	int		i;
	t_flag	flag;
	
	va_start(ap, str);
	i = -1;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			flag = which_flag(str[i+1]);
			if (flag == e_other)
				return (0);
			else
				which_action(flag, ap);
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
	int	d;;

	t = 'r';
	d = 122;
	printf("%p on est le %x octobre et la lettre du jour est : %c\n", s, d, t);
	ft_printf("%p on est le %x octobre et la lettre du jour est : %c\n", s, d, t);
}
