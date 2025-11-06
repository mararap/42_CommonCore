/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:03:29 by marapovi          #+#    #+#             */
/*   Updated: 2025/11/06 18:18:34 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// goku

#include "../inc/minitalk.h"

volatile sig_atomic_t	g_server = BUSY;

void	end_handler(int signum, siginfo_t *info, void *context)
{
	fputs ("\n\t✅ message received ✅\n", stdout);
	exit (EXIT_FAILURE);
}

static void	ack_handler(int sig)
{
	g_server = READY;
}

static void	send_char(char c, pid_t, server)
{
	int	bit;

	bit = 0;
	while (bit < CHAR_BIT)
	{
		if ((c >> i) & 1)
			kill(server, SIGUSR1);
		else
			kill(server, SIGUSR2);
		bit++;
		while (g_server == BUSY)
			usleep(39);
		g_server == BUSY;
	}
}

/*
int	mt_char_to_bin(char c, int pid)
{
	int	i;
	int	j;
	
	i = 7;
	j = 0;
	while (i >= 0)
	{
		j = 0;
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_end_of_sig = 0)
		{
			if (j == 42)
			{
				ft_printf("No response from server.");
				exit (0);
			}
			j++;
			usleep(99);
		}
		g_end_of_sig = 0;
	}
	return (0);
}*/
/*
int	main(int ac, char **av)
{
	pid_t	client;
	char	*msg;

	if (ac != 3)
	{
		fputs("usage = ./client <PID> \"msg\"\n");
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}*/

int	main(int ac, char **av)
{
	pid_t	server;
	char	*msg;
	int		i;

	i = 0;
	if (ac != 3)
	{
		fputs("usage: ./client <server> \"msg\"\n");
		return (EXIT_FAILURE);
	}
	server = ft_atoi(av[1]);
	msg = av[2];
	sigaction(SIGUSR1, ack_hander, false);
	sigaction(SIGUSR2, end_handler, false);
	while (msg[i])
		send_char(msg[i++, server]);
	send_char('\0', server);
	return (EXIT_SUCCESS);
}
