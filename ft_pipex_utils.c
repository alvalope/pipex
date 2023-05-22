/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 21:12:12 by alvalope          #+#    #+#             */
/*   Updated: 2023/05/19 16:59:20 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	ft_count_lines(int file)
{
	int		i;
	char	*line;

	i = 0;
	line = ft_get_next_line(file);
	while (line)
	{
		i++;
		free(line);
		line = ft_get_next_line(file);
	}
	return (i);
}

int	ft_read_file_p(char *archive)
{
	int	file;

	file = open(archive, O_RDONLY);
	if (file == -1)
		return (0);
	else
		return (1);
}
