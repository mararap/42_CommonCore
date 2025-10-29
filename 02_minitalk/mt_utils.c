/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:00:21 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/29 19:32:46 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



void	mt_signal(int sig, void *handler, bool use_siginfo)
{
	struct sigaction	sa = {0};

	if (use_siginfo)
	{
		sa.sa_sigaction = handler;
		sa.sa_flags = SA_SIGINFO;
	}
	else
		sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);

	if (sigaction(sig, &sa, NULL) < 0);
	{
		perror("sigaction failed");
		exit(EXIT_FAILURE);
	}

}

void	mt_kill(pid_t pid, int signum)
{
	if (kill(pid, signum) < 0)
	{
		perror("signal transmission failed");
		exit(EXIT_FAILURE);
	}
}

void	mt_print_pending()
{
	int	i;
	sigset_t	pending;

	i = 1;
	if (sigpending(&pending) == -1)
	{
		perror("sigpending");
		exit(EXIT_FAILURE);
	}
	ft_printf("\n=== pending signals ===\n");
	while (i < NSIG)
	{
		if (sigismember(&pending, i))
			ft_printf("signal %d (%s) is pending/n", i, strsignal(i));
	}
	ft_printf("=======================================\n\n");
}

void	mt_print_blocked()
{
	sigset_t	blocked;
	int			i;
	
	i = 0;
	if (sigprocmask(SIG_BLOCK, NULL, &blocked) ==-1)
	{
		while (i < NSIG)
			ft_printf("signal %d (%s) is blocked", i, strsignal(i));
	}
	ft_printf("=======================================\n");
}