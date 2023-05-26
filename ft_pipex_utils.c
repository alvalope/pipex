/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 21:12:12 by alvalope          #+#    #+#             */
/*   Updated: 2023/05/26 09:43:46 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	ft_verify_file(char *archive)
{
	int	file;

	file = open (archive, O_RDONLY);
	if (file == -1)
		file = -1;//
	return (1);
	/*if (access(archive, F_OK) == -1)
		return (1);//exit(EXIT_FAILURE);
	else
		return (1);*/
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
