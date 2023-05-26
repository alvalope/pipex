/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 21:14:57 by alvalope          #+#    #+#             */
/*   Updated: 2023/05/26 13:10:06 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	ft_check_first_command(t_pipex *p, char *command)
{
	p->arg1 = ft_split_quote(command, ' ');
	p->path1 = ft_strjoin("/bin/", p->arg1[0]);
	if (access(p->path1, F_OK) == -1 || access(p->path1, X_OK) == -1)
	{
		free(p->path1);
		p->path1 = ft_strjoin("/usr/bin/", p->arg1[0]);
		if (access(p->path1, F_OK) == -1 || access(p->path1, X_OK) == -1)
		{
			ft_printf("Command not found: %s\n", p->arg1[0]);
			ft_free_path_com(p, 1);
			p->command_not_found = 1;
		}
	}
}

void	ft_check_second_command(t_pipex *p, char *command)
{
	p->arg2 = ft_split_quote(command, ' ');
	p->path2 = ft_strjoin("/usr/bin/", p->arg2[0]);
	if (access(p->path2, F_OK) == -1 || access(p->path2, X_OK) == -1)
	{
		free(p->path2);
		p->path2 = ft_strjoin("/bin/", p->arg2[0]);
		if (access(p->path2, F_OK) == -1 || access(p->path2, X_OK) == -1)
		{
			if (ft_strncmp(p->arg2[0], "exit", 4) == 0)
			{
				ft_free_path_com(p, 2);
				exit(EXIT_SUCCESS);
			}	
			else
			{
				ft_printf("Command not found: %s\n", p->arg2[0]);
				ft_free_path_com(p, 2);
			}
		}
	}
}
