/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:04:21 by marapovi          #+#    #+#             */
/*   Updated: 2025/11/13 16:31:56 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

static t_serv_status	g_server;

static void	mt_handler_serv(int sig, siginfo_t *info, void *context)
{
	int	bit;

	bit = 0;
	(void)context;
	if (g_server.pid_cl == 0)
		g_server.pid_cl = info->si_pid;
	if (info->si_pid != g_server.pid_cl)
		return ;
	if (sig == SIGUSR1)
		bit = 0;
	else if (sig == SIGUSR2)
		bit = 1;
	kill(g_server.pid_cl, SIGUSR1);
	g_server.curr_byte = ((g_server.curr_byte << 1) | bit);
	g_server.bitcount++;
	if (g_server.bitcount == 8)
	{
		g_server.ready = 1;
		g_server.bitcount = 0;
	}
}

static int	mt_receive_len(void)
{
	int				len;
	int				i;
	unsigned char	byte;

	len = 0;
	i = 0;
	while (i < 4)
	{
		while (!g_server.ready)
			pause();
		byte = g_server.curr_byte;
		g_server.ready = 0;
		g_server.curr_byte = 0;
		len = (len << 8) | byte;
		i++;
	}
	return (len);
}

static void	mt_sig_setup_srv(struct sigaction *sa)
{
	ft_memset(&g_server, 0, sizeof(g_server));
	ft_memset(sa, 0, sizeof(*sa));
	sigemptyset(&sa->sa_mask);
	sa->sa_flags = SA_SIGINFO;
	sa->sa_sigaction = mt_handler_serv;
	if (sigaction(SIGUSR1, sa, NULL) == -1
		|| (sigaction(SIGUSR2, sa, NULL) == -1))
	{
		write (2, "Error: sigaction\n", 17);
		exit (1);
	}
}

static char	*mt_receive_msg(int len)
{
	char			*buffer;
	int				i;
	unsigned char	byte;
	
	byte = 0;
	buffer = malloc(len + 1);
	if (!buffer)
	{
		write (2, "Error: malloc\n", 14);
		exit (4);
	}
	i = 0;
	while (i < len)
	{
		while (!g_server.ready)
			pause();
		byte = g_server.curr_byte;
		g_server.ready = 0;
		g_server.curr_byte = 0;
		buffer[i] = byte;
		i++;
	}
	buffer[len] = '\0';
	return (buffer);
}

int	main(void)
{
	struct sigaction	sa;
	int					len;
	char				*buffer;

	mt_sig_setup_srv(&sa);
	ft_printf ("PID = %d\n", getpid());
	while (1)
	{
		len = mt_receive_len();
		buffer = mt_receive_msg(len);
		ft_printf("%s\n", buffer);
		free(buffer);
		g_server.pid_cl = 0;
	}
	return (0);
}
