/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:41:26 by marapovi          #+#    #+#             */
/*   Updated: 2025/11/14 20:08:37 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	mt_sig_setup_cl(void)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = mt_handler_ack;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		write (2, "Error: sigaction failure\n", 25);
		exit(5);
	}
}

int	main(int ac, char **av)
{
	pid_t	server;
	char	*message;

	server = 0;
	if (ac != 3 || !av[1][0] || !av[2][0])
	{
		write (2, "Error: invalid input\n", 21);
		return (2);
	}
	signal(SIGINT, SIG_IGN);
	if (mt_atol(av[1]) == (long)INT_MIN - 1 || mt_atol(av[1]) == -1)
	{
		write (2, "Error: invalid PID\n", 19);
		return (3);
	}
	server = (pid_t)mt_atol(av[1]);
	message = av[2];
	mt_send_str(server, message);
	return (0);
}
