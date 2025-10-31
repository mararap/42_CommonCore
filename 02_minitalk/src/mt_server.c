/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:04:21 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/30 23:31:39 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"
#include <stdio.h>

static int	g_stop = 0;

static void	mt_handler(int sig, siginfo_t *x, void *y)
{
	(void)x;
	(void)y;
	const char	msg[] = "Happy Birthday!\n";
	
	if (sig == SIGUSR1)
	{
		write(1, msg, sizeof(msg) - 1);
		g_stop = 1;
	}
}

int	main(void)
{
	struct sigaction	sa;
	
	ft_memset(&sa, 0, sizeof(sa));
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = mt_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || (sigaction(SIGUSR2, &sa, NULL) == -1))
	{
		perror("sigaction");
		return (1);
	}
	printf("PID = %d\n", getpid());
	while (!g_stop)
		pause();
	return (0);
}