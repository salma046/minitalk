/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salaoui <salaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 14:31:24 by salaoui           #+#    #+#             */
/*   Updated: 2024/05/30 11:54:41 by salaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	msg_reached(int a)
{
	if (a == SIGUSR2)
		ft_printf("\033[93mServer Recieved Your msg\033[0m\n");
}

void	send_bits(int pid, char *string)
{
	int	i;
	int	bit;

	i = 0;
	while (string[i])
	{
		bit = 7;
		while (bit >= 0)
		{
			if ((string[i] & (1 << bit)) != 0)
			{
				if (kill(pid, SIGUSR2) == -1)
					exit(write(1, "Error PID\n", 10));
			}
			else
			{
				if (kill(pid, SIGUSR1) == -1)
					exit(write(1, "Error PID\n", 10));
			}
			usleep(300);
			bit--;
		}
		i++;
	}
}

void	send_char(int pid, char a)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((a & (1 << bit)) != 0)
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(write(1, "Error\n", 6));
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(write(1, "Error\n", 6));
		}
		usleep(300);
		bit--;
	}
}

int	main(int ac, char *argv[])
{
	int		pid;
	char	a;

	a = '\0';
	if (ac != 3)
		exit(write(1, "Error\n", 6));
	pid = ft_atoi(argv[1]);
	signal(SIGUSR2, msg_reached);
	send_bits(pid, argv[2]);
	send_char(pid, a);
	return (0);
}
