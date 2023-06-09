/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 23:06:41 by druina            #+#    #+#             */
/*   Updated: 2023/07/06 15:29:40 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Case of having only redirections without any executables

void	case_only_redirections(char ***array)
{
	while (*(*array) && **(*array) != '|' && **(*array) != '\0')
		(*array)++;
	if (*(*array))
		(*array)++;
}

// Checks if the current arguemnts until the pipe have
//	any tokens that are not redirections.

int	cmd_len(char **array)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (array[i] && ft_strncmp(array[i], "|", 1) != 0)
	{
		if ((ft_strncmp(array[i], "<", 1) == 0
				|| ft_strncmp(array[i], ">", 1) == 0)
			&& ft_strlen(array[i]) > 1)
			i += 2;
		else
		{
			len++;
			i++;
		}
	}
	return (len);
}

// Case of having an empty token after parsing. Moves the pointer to be NULL.

void	case_empty_cmd(char ***array)
{
	if ((*array)[1])
		(*array) += 2;
	else
		(*array)++;
}

// Checks if it's a redirection

int	is_redir(char ***array)
{
	if ((ft_strncmp(**array, "<", 1) == 0
			|| ft_strncmp(**array, ">", 1) == 0)
		&& *(*array + 1))
		return (1);
	return (0);
}
