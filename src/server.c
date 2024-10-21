/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:09:36 by racasado          #+#    #+#             */
/*   Updated: 2024/10/21 11:15:45 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "../libft/libft.h"

volatile sig_atomic_t	g_client_pid = 0;

void	handler_sigusr(int sig, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	bits = 0;

	(void)context;
	g_client_pid = info->si_pid;
	if (sig == SIGUSR1)
		c |= (1 << bits);
	bits++;
	if (bits == 8)
	{
		if (c == '\0')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		c = 0;
		bits = 0;
	}
	kill(g_client_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	printf("Server PID: %d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler_sigusr;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
