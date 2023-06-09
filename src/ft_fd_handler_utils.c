/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd_handler_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:31:40 by druina            #+#    #+#             */
/*   Updated: 2023/06/02 21:28:35 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//  opens any redirected file

void	find_and_open_fds(char **array)
{
	int	fd;
	int	i;

	fd = 0;
	i = 0;
	while (array[i] != 0 && *array[i] != '|')
	{
		if (ft_strncmp(array[i], "<<", 2) == 0
			&& array[i] != find_last_infile(array))
			fd = here_doc(array[i + 1]);
		else if (ft_strncmp(array[i], ">>", 2) == 0)
			fd = open(array[i + 1], O_CREAT | O_RDWR | O_APPEND, 0664);
		else if (ft_strncmp(array[i], ">", 1) == 0 && ft_strlen(array[i]) != 2)
			fd = open(array[i + 1], O_CREAT | O_RDWR | O_TRUNC, 0664);
		if (fd == -1)
			perror(array[i + 1]);
		i++;
		if (fd > 2)
			close(fd);
		fd = 0;
	}
}

//finds the last outfile fd

char	*find_last_outfile(char **array)
{
	char	*last;
	int		i;

	i = 0;
	last = NULL;
	while (array[i] != 0 && *array[i] != '|')
	{
		if (ft_strncmp(array[i], ">>", 2) == 0)
			last = array[i];
		else if (ft_strncmp(array[i], ">", 1) == 0)
			last = array[i];
		i++;
	}
	return (last);
}
