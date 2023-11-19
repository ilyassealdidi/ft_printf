/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:30:09 by ialdidi           #+#    #+#             */
/*   Updated: 2023/11/19 11:03:04 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static int	ft_tolower(int c)
{
	return (c + 32 * (c >= 'A' && c <= 'Z'));
}

int	ft_putnbr_base(long nbr, int base, unsigned char is_upper)
{
	char	*arr;
	int		_printed;

	_printed = 0;
	arr = "0123456789ABCDEF";
	if (nbr < 0)
	{
		_printed += ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= base)
	{
		_printed += ft_putnbr_base(nbr / base, base, is_upper);
		return (_printed += ft_putnbr_base(nbr % base, base, is_upper));
	}
	else
	{
		if (is_upper)
			ft_putchar(arr[nbr]);
		else
			ft_putchar(ft_tolower(arr[nbr]));
		_printed++;
	}
	return (_printed);
}
