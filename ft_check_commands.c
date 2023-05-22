/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 21:14:57 by alvalope          #+#    #+#             */
/*   Updated: 2023/05/22 13:38:08 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	ft_check_first_command(t_pipex *p, char *command)
{
	int		i;
	//char	**com;

	i = 0;
	/*while (command[i] == 32 || (command[i] > 8 && command[i] < 14))
		i++;*/
	p->args1 = ft_split(command, ' ');
	p->path1 = ft_strjoin("/bin/", p->args1[0]);
	if (access(p->path1, F_OK) == -1 || access(p->path1, X_OK) == -1)
	{
		p->path1 = ft_strjoin("/usr/bin/", p->args1[0]);
		if (access(p->path1, F_OK) == -1 || access(p->path1, X_OK) == -1)
			return (ft_free_path_com(p, 1), 0);
	}
	/*if (open(p->path1, O_RDONLY) == -1)
		return (ft_free_path_com(p, com, 1), 0);*/
	/*i = 0;
	while (com[i])
		i++;
	p->args1 = (char **)malloc((i + 1) * sizeof(char *));
	i = 0;
	while (com[i])
	{
		p->args1[i] = com[i];
		i++;
	}
	p->args1[i] = 0;*/
	return (1);
}

int	ft_check_second_command(t_pipex *p, char *command)
{
	int		i;
	//char	**com;

	i = 0;
	p->args2 = ft_split(command, ' ');
	p->path2 = ft_strjoin("/usr/bin/", p->args2[0]);
	if (access(p->path2, F_OK) == -1 || access(p->path2, X_OK) == -1)
	{
		p->path2 = ft_strjoin("/bin/", p->args2[0]);
		if (access(p->path2, F_OK) == -1 || access(p->path2, X_OK) == -1)
			return (ft_free_path_com(p, 2), 0);
	}
	/*if (open(p->path2, O_RDONLY) == -1)
		return (ft_free_path_com(p, com, 2), 0);*/
	/*i = 0;
	while (com[i])
		i++;
	p->args2 = (char **)malloc((i + 1) * sizeof(char *));
	i = 0;
	while (com[i])
	{
		p->args2[i] = com[i];
		i++;
	}
	p->args2[i] = 0;*/
	return (1);
}
