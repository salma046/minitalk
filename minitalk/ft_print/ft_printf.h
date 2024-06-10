/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:10:42 by salaoui           #+#    #+#             */
/*   Updated: 2023/12/26 15:43:27 by salaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
int		ft_putchar(char c);
int		ft_putnbr(int n, char c);
int		ft_sign(int n);
int		ft_unsign(int n);
int		ft_putbase(int nb, char c);
int		ft_putstr(char *s);
int		ft_pointer(unsigned long nb);
char	*ft_strchr(const char *s, int c);

#endif
