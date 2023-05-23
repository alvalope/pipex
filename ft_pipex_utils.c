/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 21:12:12 by alvalope          #+#    #+#             */
/*   Updated: 2023/05/23 11:05:36 by alvalope         ###   ########.fr       */
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

int	ft_verify_file(char *archive)
{
	if (access(archive, F_OK) == -1)
	{
		ft_printf("No existe el archivo %s\n", archive);
		return (0);
	}
	else
		return (1);
}
