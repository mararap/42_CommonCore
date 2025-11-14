/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_client_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:03:29 by marapovi          #+#    #+#             */
/*   Updated: 2025/11/14 15:54:18 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

volatile sig_atomic_t	g_ack_received = 0;

void	mt_handler_ack(int sig, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (sig == SIGUSR1)
		g_ack_received = 1;
	else if (sig == SIGUSR2)
	{
		write (1, "\n### message received ###\n\n", 27);
		g_ack_received = 1;
	}
}

void	mt_send_bit(pid_t server, int bit)
{
	int	sig;
	int	retries;

	sig = 0;
	if (bit == 0)
		sig = SIGUSR1;
	else if (bit == 1)
		sig = SIGUSR2;
	g_ack_received = 0;
	if (kill(server, sig) == -1)
	{
		write (2, "Error: kill failure\n", 20);
		exit(3);
	}
	retries = 0;
	while (!g_ack_received && retries < MAX_RETRIES)
	{
		usleep(66);
		retries++;
	}
	if (g_ack_received == 0)
	{
		write (2, "Error: no ack received\n", 23);
		exit (6);
	}
}

static void	mt_send_char(pid_t server, unsigned char byte)
{
	int	i;
	int	bit;

	i = 7;
	while (i >= 0)
	{
		bit = (byte >> i) & 1;
		mt_send_bit(server, bit);
		i--;
	}
}

static void	mt_send_int(pid_t server, int num)
{
	mt_send_char(server, ((num >> 24) & 0xFF));
	mt_send_char(server, ((num >> 16) & 0xFF));
	mt_send_char(server, ((num >> 8) & 0xFF));
	mt_send_char(server, num & 0xFF);
}

void	mt_send_str(pid_t server, char *str)
{
	ssize_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(str);
	if (len < 0 || len > 2000000)
	{
		write (2, "Error: invalid string lenght\n", 29);
		exit (2);
	}
	mt_sig_setup_cl();
	mt_send_int(server, (int)len);
	while ((size_t)i < len)
	{
		mt_send_char(server, (unsigned char)str[i]);
		i++;
	}
}
