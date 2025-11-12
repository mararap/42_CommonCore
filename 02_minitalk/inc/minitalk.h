/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 19:44:03 by marapovi          #+#    #+#             */
/*   Updated: 2025/11/12 10:42:43 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <errno.h>
# include <limits.h>
# include "../libft/libft.h"
# include <stdbool.h>

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

// Error handling:
// 0 = success
// 1 = unexpected failure
// 2 = invalid arguments
// 3 = invalid PID, kill-error
// 4 = allocation failure
// 5 = sig setup failure
// 6 = send/ack failure

#endif // !MINITALK_H