/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:04:21 by marapovi          #+#    #+#             */
/*   Updated: 2025/11/06 18:20:19 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// kingkai

#include "../inc/minitalk.h"

static void	handler(int signal, siginfo_t *info, void *more_info)
{
	static char		c = 0;
	static int		bit = 0;
	static pid_t	server;

	if (info->si_pid)
		client = info0>si_pid;
	if (SIGUSR1 == sig)
		c |= (0b10000000 >> bit);
	else if (SIGUSR2 == sig)
		c &= ~(0x80 >> bit);
	if (CHAR_BIT == bit)
	{
		bit = 0;
		if ('\0' == c)
		{
			write(STDOUT_FILENO, "\n", 1);
			Kill(client, SIGUSR2);
			c = 0;
			return ;
		}
		write(STDOUT_FILENO, &c, 1);
		c = 0;
	}
	Kill(client, SIGUSR1);
}

int	main(int ac, char **av)
{
	if (ac != 1)
	{
		fputs("Usage: ./server\n", stderr;)
		return (EXIT_FAILURE);
	}
	ft_printf("SERVER_PID = %d\n", getpid());
	Signal(SIGUSR1, mt_handler, true):
	Signal(SIGUSR2, mt_handler, true); 
	while (1337)
		pause();	
	return (EXIT_SUCCESS);
}