/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:09:33 by racasado          #+#    #+#             */
/*   Updated: 2024/10/24 13:04:49 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft.h"

static sig_atomic_t	g_received_ack = 0;

void	ack_handler(int sig)
{
	(void)sig;
	g_received_ack = 1;
}

void	send_char(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_received_ack)
			pause();
		g_received_ack = 0;
		c >>= 1;
		i++;
	}
}

void	send_string(int pid, char *str)
{
	while (*str)
	{
		send_char(pid, *str);
		str++;
	}
	send_char(pid, '\0');
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		write(2, "Usage: ./client [server_pid] [message]\n", 40);
		return (1);
	}
	signal(SIGUSR1, ack_handler);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		write(2, "Invalid PID.\n", 13);
		return (1);
	}
	send_string(pid, argv[2]);
	return (0);
}
