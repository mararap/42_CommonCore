/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 19:35:16 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/29 19:15:55 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

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
	mt_signal(SIGUSR1, ack_halnder, false);
	mt_signal(SIGUSR2, end_handler, false);
	while (msg[i])
		mt_send_char(msg[i++, server]);
	mt_send_char('\0', server);
	return (EXIT_SUCCESS);
}