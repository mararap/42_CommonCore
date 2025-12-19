/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:01:59 by marapovi          #+#    #+#             */
/*   Updated: 2025/12/19 18:05:50 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int ac, char **av)
{
	// REPL
	// read - evaluate - print - loop
	while (1)
	{
		// 1) get line

		// 2) 
	(void)ac;
	int	status;

	if (fork() == 0
		execvp(av[1], av + 1);

	wait(&status);
	return (0);
}
