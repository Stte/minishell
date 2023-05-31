/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:16:50 by tspoof            #+#    #+#             */
/*   Updated: 2023/05/31 07:47:54 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell(char *line, char *env[])
{
	t_vec	envs;
	t_node	*head;
	int		**pipe_nbr;

	envs = ft_copyenv(env);
	head = ft_parse_args(line, envs);
	if (!head)
		return ;
	pipe_nbr = piper(line, head);
	ft_executor(head, envs);
	free_nodes(head);
}

int	main(int argc, char *argv[], char *env[])
{
	char	*line;

	(void)argv;
	argc = 0;
	while (1)
	{
		printf("TERMINAL:");
		line = readline(NULL);
		add_history(line);
		minishell(line, env);
		free(line);
		wait(NULL);
	}
	return (0);
}
