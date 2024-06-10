/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:08:11 by salaoui           #+#    #+#             */
/*   Updated: 2023/12/26 15:07:20 by salaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len = 1;
	}
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static	int	ft_unslen(unsigned int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len = 1;
	}
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

int	ft_putnbr(int n, char c)
{
	if (c == 'u')
	{
		return (ft_unsign(n));
	}
	else
		return (ft_sign(n));
}

int	ft_unsign(int n)
{
	unsigned int	l;

	l = (unsigned int)n;
	if (l < 10)
	{
		ft_putchar(l + '0');
	}
	else
	{
		ft_unsign(l / 10);
		ft_putchar(l % 10 + '0');
	}
	return (ft_unslen(l));
}

int	ft_sign(int n)
{
	if (n == -2147483648)
	{
		write (1, "-", 1);
		write (1, "2147483648", 10);
		return (11);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_sign(-n);
	}
	else if (n <= 9)
	{
		ft_putchar(n + '0');
	}
	else
	{
		ft_sign(n / 10);
		ft_putchar(n % 10 + '0');
	}
	return (ft_len(n));
}
