/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salaoui <salaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 20:33:22 by salaoui           #+#    #+#             */
/*   Updated: 2024/05/28 09:50:05 by salaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

int	main(int ac, char *argv[])
{
	int	pid;

	if (ac != 3)
		exit(write(1, "Error\n", 6));
	pid = ft_atoi(argv[1]);
	send_bits(pid, argv[2]);
	return (0);
}
