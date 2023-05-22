/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 19:03:56 by tspoof            #+#    #+#             */
/*   Updated: 2023/05/22 12:29:15 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void	case_only_redirections(char ***array)
{
	while (*(*array) && **(*array) != '|' && **(*array) != '\0')
		(*array)++;
	if (*(*array))
		(*array)++;
}

int	len_node_cmd(char **array)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (array[i] && ft_strncmp(array[i], "|", 1) != 0)
	{
		if (ft_strncmp(array[i], "<", 1) == 0 || ft_strncmp(array[i], ">",
				1) == 0)
			i += 2;
		else
		{
			len++;
			i++;
		}
	}
	return (len);
}

char	**get_node_cmd(char ***array)
{
	char	**answer;
	int		i;

	i = 0;
	if (len_node_cmd(*array) == 0)
		return (case_only_redirections(array), NULL);
	answer = (char **)malloc(sizeof(char *) * (len_node_cmd(*array) + 1));
	if (!answer)
		return (NULL);
	while (*(*array) && **(*array) != '|' && **(*array) != '\0')
	{
		if (ft_strncmp(*(*array), "<", 1) == 0 || ft_strncmp(*(*array), ">",
				1) == 0)
			(*array) += 2;
		else
		{
			answer[i++] = *(*array);
			(*array)++;
		}
	}
	if (*(*array))
		(*array)++;
	answer[i] = 0;
	return (answer);
}

t_node	*new_node(char ***array, int *here_doc_case_of_error)
{
	t_node	*node;

	if (array == NULL)
		return (NULL);
	node = (t_node *)ft_calloc(1 ,sizeof(t_node));
	if (!node)
		return (NULL);
	node = ft_fd_handler((*array), here_doc_case_of_error, node);
	node->full_cmd = get_node_cmd(array);
	if (!**array)
		node->next = NULL;
	else
		node->next = new_node(array, here_doc_case_of_error);
	return (node);
}

t_node	*ft_parse_args(char **array)
{
	t_node		*head;
	static int	here_doc_case_of_error = 0;

	head = new_node(&array, &here_doc_case_of_error);
	return (head);
}
