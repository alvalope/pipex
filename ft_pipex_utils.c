/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 21:12:12 by alvalope          #+#    #+#             */
/*   Updated: 2023/05/26 12:20:06 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	ft_free_all(t_pipex *p)
{
	int	i;

	i = 0;
	while (p->arg1[i])
	{
		free(p->arg1[i]);
		i++;
	}
	free(p->arg1);
	i = 0;
	while (p->arg2[i])
	{
		free(p->arg2[i]);
		i++;
	}
	free(p->arg2);
	i = 0;
	free (p->path1);
	free (p->path2);
}

void	ft_free_path_com(t_pipex *p, int n)
{
	int	i;

	i = 0;
	if (n == 2)
	{
		free(p->path2);
		while (p->arg2[i])
		{
			free(p->arg2[i]);
			i++;
		}
		free(p->arg2);
	}
	i = 0;
	if (p->command_not_found == 0)
	{
		free(p->path1);
		while (p->arg1[i])
		{
			free(p->arg1[i]);
			i++;
		}
		free(p->arg1);
	}
}
