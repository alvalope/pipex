/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 21:12:12 by alvalope          #+#    #+#             */
/*   Updated: 2023/05/19 16:43:45 by alvalope         ###   ########.fr       */
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

int	ft_read_file_p(t_pipex *p, char *archive)
{
	int	i;
	int	file;

	file = open(archive, O_RDONLY);
	if (file == -1)
		return (0);
	i = ft_count_lines(file);
	p->lines = i;
	if (i > 0)
		p->archive_lines = (char **)ft_calloc((i + 1) * sizeof(char *), 1);
	close(file);
	file = open (archive, O_RDONLY);
	if (file == -1)
		return (free(p->archive_lines), 0);
	i = 0;
	p->archive_lines[i] = ft_get_next_line(file);
	while (p->archive_lines[i])
	{
		i++;
		p->archive_lines[i] = ft_get_next_line(file);
	}
	return (1);
}
