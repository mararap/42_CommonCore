/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 19:44:03 by marapovi          #+#    #+#             */
/*   Updated: 2025/11/14 14:54:05 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h> //write, getpid, usleep
# include <stdlib.h> //malloc, free, exit
# include <limits.h> //INT_MIN (ft_atol)
# include "../libft/libft.h"
# include <stdbool.h> //true/false (ft_atol)
# include <sys/types.h> //pid_t
# include <signal.h> //signals

# define MAX_RETRIES 7000

typedef struct s_serv_status
{
	volatile sig_atomic_t	bitcount;
	volatile sig_atomic_t	curr_byte;
	volatile sig_atomic_t	pid_cl;
	volatile sig_atomic_t	ready;
}					t_serv_status;

void			mt_handler_ack(int sig, siginfo_t *info, void *context);
void			mt_send_str(pid_t server, char *str);
long			mt_atol(char *str);
void			mt_sig_setup_cl(void);
void			mt_send_bit(pid_t server, int bit);

// Error handling:
// 0 = success
// 1 = unexpected failure
// 2 = invalid arguments
// 3 = invalid PID, kill-error
// 4 = allocation failure
// 5 = sig setup failure
// 6 = send/ack failure

#endif // !MINITALK_H