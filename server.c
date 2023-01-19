/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:09:36 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/01/19 17:15:23 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/* Show pid and waiting for clients signal */
int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID = %i\n", getpid());
	sa.sa_sigaction = ft_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		sleep(1);
}

/* Recieved message from client bite a bite */
void	ft_handler(int sig, siginfo_t *si, void *unused)
{
	static char	c = 0;
	static int	i = 0;

	sig -= SIGUSR1;
	if (!sig)
		c = c << 1;
	else
		c = c << 1 | 1;
	i++;
	if (i == 8)
	{
		if (c == 0)
			kill(si->si_pid, SIGUSR2);
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
}
