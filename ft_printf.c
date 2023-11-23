/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 08:48:43 by ialdidi           #+#    #+#             */
/*   Updated: 2023/11/20 09:31:50 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"

static int	check_format(char format, va_list args)
{
	if (format == 'd' || format == 'i')
		return (ft_putnbr_base(va_arg(args, int), 10, 0));
	else if (format == 'u')
		return (ft_putnbr_base(va_arg(args, unsigned int), 10, 0));
	else if (format == 'x')
		return (ft_putnbr_base((long)va_arg(args, unsigned int), 16, 0));
	else if (format == 'X')
		return (ft_putnbr_base((long)va_arg(args, unsigned int), 16, 1));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == '%')
		return (ft_putchar('%'));
	else if (format == 'p')
	{
		ft_putstr("0x");
		return (ft_print_address((unsigned long)va_arg(args, void *)) + 2);
	}
	else
		return ft_putchar(format);
}

int	ft_printf(const char *s, ...)
{
	int		_printed;
	va_list	args;

	if (write(1, "", 0) < 0)
		return (-1);
	va_start(args, s);
	_printed = 0;
	while (*s)
	{
		if (*s == '%')
		{
			if (*++s)
				_printed += check_format(*s, args);
			else
				break ;
		}
		else
			_printed += write(1, s, 1);
		s++;
	}
	va_end(args);
	return (_printed);
}
