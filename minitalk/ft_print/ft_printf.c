/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:20:06 by salaoui           #+#    #+#             */
/*   Updated: 2023/12/26 17:12:15 by salaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_format(va_list arg, char s)
{
	if (s == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (s == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (s == 'p')
	{
		write(1, "0x", 2);
		return ((ft_pointer(va_arg(arg, unsigned long))) + 2);
	}
	else if (s == 'd' || s == 'i' || s == 'u')
		return (ft_putnbr(va_arg(arg, int), s));
	else if (s == 'x' || s == 'X')
		return (ft_putbase(va_arg(arg, int), s));
	else if (s == '%')
		return (ft_putchar('%'));
	else
		return (-1);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		result;
	int		len;
	va_list	arg;

	i = 0;
	result = 0;
	va_start(arg, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%' && ft_strchr ("scpxXdiu%", s[i + 1]))
		{
			len = ft_format (arg, s[i + 1]);
			result = result + len;
			i++;
		}
		else
		{
			ft_putchar(s[i]);
			result++;
		}
		i++;
	}
	va_end(arg);
	return (result);
}
