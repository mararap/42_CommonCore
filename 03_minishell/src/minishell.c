/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:01:59 by marapovi          #+#    #+#             */
/*   Updated: 2025/12/19 21:11:08 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	msh_print_banner(void)
{
	printf("																						 \n"
		   "     ██╗██╗   ██╗███╗   ███╗ █████╗ ███████╗██╗  ██╗██╗         ██╗   ██╗ ██╗    ██████╗ \n"
		   "     ██║██║   ██║████╗ ████║██╔══██╗██╔════╝██║  ██║██║         ██║   ██║███║   ██╔═████╗\n"
		   "     ██║██║   ██║██╔████╔██║███████║███████╗███████║██║         ██║   ██║╚██║   ██║██╔██║\n"
		   "██   ██║██║   ██║██║╚██╔╝██║██╔══██║╚════██║██╔══██║██║         ╚██╗ ██╔╝ ██║   ████╔╝██║\n"
		   "╚█████╔╝╚██████╔╝██║ ╚═╝ ██║██║  ██║███████║██║  ██║███████╗     ╚████╔╝  ██║██╗╚██████╔╝\n"
		   " ╚════╝  ╚═════╝ ╚═╝     ╚═╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚══════╝      ╚═══╝   ╚═╝╚═╝ ╚═════╝ \n"
		   "																						 \n");
}

void	msh_getcwd(char *buf, size_t size)
{
	if (NULL == getcwd(buf, size))
		perror("Error");
}

char	*msh_read_line(void)
{
	char	*buf;
	size_t	BUFFER_SIZE;
	char	curr_wd[BUFSIZ];

	buf = NULL;
	msh_getcwd(curr_wd, sizeof(curr_wd));
	printf("%s$>", curr_wd);
	if (getline(&buf, &BUFFER_SIZE, stdin) == -1)
	{
		buf = NULL;
		if (feof(stdin))
			printf("[EOF]");
		else
			perror("Error");
	}
	return (buf);
}

int	main(void)
{
	char *line;
	// REPL
	// read->evaluate->print/execute->loop
	msh_print_banner();
	while ((line = msh_read_line()))
	{
		printf("%s\n", line);
		// 2) evaluate - get tokens gettok
		//		->lexing->parsing EVALUATIONS

		// 3) Exec
	}
	return (0);
}
