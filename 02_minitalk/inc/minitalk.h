/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 19:44:03 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/29 19:37:12 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <limits.h>
#include "../libft/libft.h"
#include <stdbool.h>

#define BUSY		0
#define READY		1
/*
typedef struct	__siginfo
{
	int				si_signo;			// signal number
	int				si_errno;			// errno association
	int				si_code;			// signal code
	pid_t			si_pid;				// sending process
	uid_t			si_uid;				// sender's ruid
	int				si_status;			// exit value
	void			*si_addr;			// faulting instruction
	union			sigval si_value;	// signal value
	long			si_band;			// band event for SIGPOLL
	unsigned long	__pad[7];			// reserved for future use
}				siginfo_t;
*/

void	mt_signal(int sig, void *handler, bool use_siginfo);
void	mt_kill(pid_t pid, int signum);

#endif // !MINITALK_H