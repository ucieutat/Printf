/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucieutat <cieutatulin@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:23:26 by ucieutat          #+#    #+#             */
/*   Updated: 2021/11/24 18:46:18 by ucieutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>

typedef enum	e_flag
{
	e_char,
	e_string,
	e_pointer,
	e_digit,
	e_int,
	e_unsigned,
	e_hex,
	e_percent,
	e_other,
}	t_flag;

t_flag	which_flag(char c);
int		ft_printf(char *str, ...);
void	which_action (t_flag flag, va_list ap);
void	print_char(va_list ap);
void	print_string(va_list ap);
void	print_digit(va_list ap);
void	print_unsigned(va_list ap);
void	print_hex(va_list ap);
void	ft_putstr(char *s);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_puthex(uint64_t	u, char *base);
void	ft_putptr(va_list ap);
#endif
