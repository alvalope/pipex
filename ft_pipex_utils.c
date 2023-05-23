/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 21:12:12 by alvalope          #+#    #+#             */
/*   Updated: 2023/05/23 13:59:18 by alvalope         ###   ########.fr       */
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

void	ft_free_all(t_pipex *p)
{
	int	i;

	i = 0;
	while (p->args1[i])
	{
		free(p->args1[i]);
		i++;
	}
	free(p->args1);
	i = 0;
	while (p->args2[i])
	{
		free(p->args2[i]);
		i++;
	}
	free(p->args2);
	i = 0;
	free (p->path1);
	free (p->path2);
}

void	ft_free_path_com(t_pipex *p, int n)
{
	int	i;

	free(p->path1);
	i = 0;
	if (n == 2)
	{
		free(p->path2);
		while (p->args2[i])
		{
			free(p->args2[i]);
			i++;
		}
		free(p->args2);
	}
	i = 0;
	while (p->args1[i])
	{
		free(p->args1[i]);
		i++;
	}
	free(p->args1);
}
