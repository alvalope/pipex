/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:14:19 by alvalope          #+#    #+#             */
/*   Updated: 2023/05/23 13:40:31 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

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

void	ft_free_com(char **com)
{
	int	i;

	i = 0;
	while (com[i])
	{
		free(com[i]);
		i++;
	}
	free(com);
}
