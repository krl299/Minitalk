/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:09:28 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/02/02 10:47:43 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/* Receive server pid and msg to send back to server process */
int	main(int argc, char **argv)
{
	int		server_pid;
	char	*msg;

	signal(SIGUSR2, ft_handler2);
	if (argc != 3)
	{
		ft_printf("./client [server-pid] [message]\n");
		exit(0);
	}
	server_pid = ft_atoi(argv[1]);
	msg = argv[2];
	ft_send_msg(msg, server_pid);
	return (0);
}

/* Server dispatched message */
void	ft_handler2(int sig)
{
	ft_printf("Message dispatched\n");
}

/* Send the message to server process */
void	ft_send_msg(char *msg, int pid)
{
	int	i;
	int	j;

	i = -1;
	while (msg[++i])
		ft_send_byte((unsigned)msg[i], pid);
	ft_send_byte('\0', pid);
}

/* Send byte to pid */
void	ft_send_byte(unsigned char c, int pid)
{
	int	j;

	j = 7;
	while (j >= 0)
	{
		if (c >> j & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		j--;
	}
}
