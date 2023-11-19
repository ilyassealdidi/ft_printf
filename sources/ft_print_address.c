/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:13:13 by ialdidi           #+#    #+#             */
/*   Updated: 2023/11/19 11:02:51 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_print_address(unsigned long nbr)
{
	char	*arr;
	int		_printed;

	_printed = 0;
	arr = "0123456789abcdef";
	if (nbr >= 16)
	{
		_printed += ft_print_address(nbr / 16);
		return (_printed += ft_print_address(nbr % 16));
	}
	else
	{
		ft_putchar(arr[nbr]);
		_printed++;
	}
	return (_printed);
}
