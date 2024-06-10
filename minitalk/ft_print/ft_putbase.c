/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 10:50:36 by salaoui           #+#    #+#             */
/*   Updated: 2023/12/26 15:39:59 by salaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_nbase(unsigned int nb, char c, char *base)
{
	int				len;
	unsigned int	n;

	len = 0;
	n = (unsigned int)nb;
	if (n >= 16)
	{
		len += put_nbase(n / 16, c, base);
		len += put_nbase(n % 16, c, base);
	}
	else
	{
		write(1, &base[n], 1);
		len++;
	}
	return (len);
}

int	ft_putbase(int nb, char c)
{
	char	*base;
	int		len;

	len = 0;
	if (c == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (nb < 0)
	{
		return (put_nbase(nb, c, base));
	}
	if (nb >= 16)
	{
		len += ft_putbase(nb / 16, c);
		len += ft_putbase(nb % 16, c);
	}
	else
	{
		write(1, &base[nb], 1);
		len++;
	}
	return (len);
}
