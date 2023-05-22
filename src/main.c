/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:16:50 by tspoof            #+#    #+#             */
/*   Updated: 2023/05/22 13:52:43 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

int	main(int argc, char *argv[]/*, char *env[]*/)
{
	char	*line = "< Makefile < dud | echo \"/Users/druina/Desktop/github/minishell 'hola'\" /Users/druina/src | << dude  'tr' -d / > outfile | echo \"'hi'\"  >ok | echo \"hi\" | echo 'he'| echo << dean  >>yep";
	char	*temp;
	char 	**temp1;
	char	**str;
	char	**str1;
	t_node 	*head;
	int		i;
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
	temp1 = str1;
	head = ft_parse_args(str1);
	while (head->next != NULL)
	{
		if (head->full_cmd == NULL)
			printf("NULL");
		else
		{
			printf("PATH: ");
		while (head->full_cmd[i] != 0)
		{
			printf("%s ",head->full_cmd[i]);
			i++;
		}
		}
		i = 0;
		printf("\n");
		printf("infile: %d\n", head->infile);
		printf("outfile: %d\n", head->outfile);
		head = head->next;
	}
	printf("PATH: ");
	while (head->full_cmd[i] != 0)
		{
			printf("%s ",head->full_cmd[i]);
			i++;
		}
		i = 0;
		printf("\n");
		printf("infile: %d\n", head->infile);
		printf("outfile: %d\n", head->outfile);
	free_2d(temp1);

	return (0);
}
