/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:16:50 by tspoof            #+#    #+#             */
/*   Updated: 2023/04/23 18:31:09 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char	*line = ft_strdup("<Makefile cat | echo \"$PWD 'hola'\" ~/src | 'tr' -d / >outfile");
	char	*str;

	str = get_token(&line);
	free (str);
	free (line);
	// str = get_token(&line);
	// str = get_token(&line);
	// str = get_token(&line);
	// str = get_token(&line);
	return (0);
}
