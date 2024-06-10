/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salaoui <salaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 20:33:07 by salaoui           #+#    #+#             */
/*   Updated: 2024/05/30 12:09:45 by salaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handle(int a, siginfo_t *info, void *vp)
{
	static char	i = 0;
	static int	bit = 7;
	static int	pid;

	(void)vp;
	if (pid != info->si_pid)
	{
		i = 0;
		bit = 7;
		pid = info->si_pid;
	}
	if (a == SIGUSR2)
		i = i | (1 << bit);
	bit--;
	if (bit == -1)
	{
		ft_printf("%c", i);
		i = 0;
		bit = 7;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sig;

	pid = getpid();
	ft_printf("your pid is: %i\n", pid);
	sig.sa_sigaction = ft_handle;
	sig.sa_flags = SA_SIGINFO;
	while (1)
	{
		if (sigaction(SIGUSR1, &sig, NULL) == -1)
			exit(write(1, "Error\n", 6));
		if (sigaction(SIGUSR2, &sig, NULL) == -1)
			exit(write(1, "Error\n", 6));
		usleep(300);
	}
	return (0);
}
