/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_operators.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 19:07:30 by tspoof            #+#    #+#             */
/*   Updated: 2023/05/17 14:12:33 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// creates the new array and allocates

char	**divide_into_array(char **array, char **answer)
{
	int		i;
	int		offset;
	char	*temp;

	offset = 0;
	i = 0;
	while (array[i] != 0)
	{
		if (check_for_operator(array[i]) == 0)
			answer[i + offset] = no_operator(answer, array, &offset, &i);
		else
		{
			temp = array[i];
			while (*array[i])
			{
				answer[i + offset] = malloc_new_token(&array[i]);
				if (*array[i])
					offset++;
			}
			array[i] = temp;
			i++;
		}
	}
	return (answer);
}

// part of find_proper_allocation

void	get_allocation_len(char *array, int *count)
{
	int	offset;

	offset = 0;
	offset = check_for_operator(array);
	if (offset == 0)
		(*count)++;
	else
	{
		while (len_to_operator(&array, NULL))
		{
			(*count)++;
			if (!*array)
				break ;
		}
	}
}

//Find proper allocation for 2D array

int	find_new_array_len(char **array, int i)
{
	int		count;

	count = 0;
	while (array[i] != 0)
	{
		get_allocation_len(array[i], &count);
		i++;
	}
	return (count);
}

//Split the tokens into operators

char	**ft_split_operators(char **array)
{
	char	**answer;
	char	**temp;
	int		count;

	if (array == NULL)
		return (NULL);
	temp = array;
	count = find_new_array_len(array, 0);
	answer = (char **)malloc(sizeof(char *) * (count + 1));
	if (!answer)
		return (NULL);
	answer[count] = 0;
	answer = divide_into_array(temp, answer);
	// free_2d(array);
	return (answer);
}