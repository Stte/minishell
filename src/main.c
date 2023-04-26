/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:16:50 by tspoof            #+#    #+#             */
/*   Updated: 2023/04/25 11:35:20 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_2d(char **str)
{
	char	**temp;

	temp = str;
	while (*str)
	{
		free(*str);
		str++;
	}
	free(temp);
}

int	main(int argc, char *argv[])
{
	char	*line; /*= "<Makefile cat | echo \"$PWD 'hola'\" ~/src | 'tr' -d / >outfile";*/
	char	*temp;
	char	**str;
	line = readline("TERMINAL:");
	temp = line;
	(void)argv;
	argc = 0;

	str = ft_cmd_trim(line);
	free_2d(str);
	free(temp);

	return (0);
}
