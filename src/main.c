/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:16:50 by tspoof            #+#    #+#             */
/*   Updated: 2023/05/10 15:54:41 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

int	main(int argc, char *argv[]/*, char *env[]*/)
{
	char	*line = "< Makefile cat | echo \"/Users/druina/Desktop/github/minishell 'hola'\" /Users/druina/src | 'tr' -d / > outfile | echo \"'hi'\" >> dude >ok";
	char	*temp;
	char 	**temp1;
	char	**str;
	char	**str1;
	t_node 	*head;
	int		i;
	// int		*fds;
	// line = readline("TERMINAL:");
	temp = line;
	(void)argv;
	argc = 0;
	i = 0;

	// while (*env)
	// 	printf("%s\n", *env++);
	// printf("(%s)\n", getenv("PWD"));
	// chdir("src");
	// printf("(%s)\n", getenv("PWD"));
	// char buf[100];
	// getcwd(buf, 100);
	// printf("(%s)\n", buf);

	// printf("(%s)\n", getenv("PWD"));

	str = ft_cmd_trim(line);
	str1 = ft_split_operators(str);
	free_2d(str);
	str1 = ft_str_trim(str1);
	// fds = ft_fd_handler(str1);
	// if (fds != NULL)
	// {
	// printf("%d\n", fds[0]);
	// printf("%d\n", fds[1]);
	// }
	temp1 = str1;
	head = new_node_and_link(&str1);
	while (head->next_node != NULL)
	{
		if (head->full_cmd == NULL)
			printf("NULL");
		else
		{
		while (head->full_cmd[i] != 0)
		{
			printf("%s ",head->full_cmd[i]);
			i++;
		}
		}
		i = 0;
		printf("\n");
		printf("path-name: %s\n", head->path_name);
		printf("infile: %d\n", head->infile);
		printf("outfile: %d\n", head->outfile);
		head = head->next_node;
	}
	// free(fds);
	while (head->full_cmd[i] != 0)
		{
			printf("%s ",head->full_cmd[i]);
			i++;
		}
		i = 0;
		printf("\n");
		printf("path-name: %s\n", head->path_name);
		printf("infile: %d\n", head->infile);
		printf("outfile: %d\n", head->outfile);
	free_2d(temp1);

	return (0);
}
