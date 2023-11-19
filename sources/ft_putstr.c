/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 08:35:48 by ialdidi           #+#    #+#             */
/*   Updated: 2023/11/19 11:03:07 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_putstr(char *s)
{
	int	_printed;

	_printed = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (*s)
		_printed += ft_putchar(*s++);
	return (_printed);
}
