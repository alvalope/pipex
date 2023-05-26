/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:38:38 by alvalope          #+#    #+#             */
/*   Updated: 2023/05/26 09:47:11 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	ft_exe_first_command(t_pipex *p)
{
	if (execve(p->path1, p->args1, 0) == -1)
		exit(EXIT_FAILURE);
	return (1);
}

int	ft_exe_second_command(t_pipex *p)
{
	if (execve(p->path2, p->args2, 0) == -1)
		exit(EXIT_FAILURE);
	return (1);
}

int	ft_do_first_command(t_pipex *p, char *fl_1, int fd[2])
{
	int	file;

	close(fd[0]);
	file = open (fl_1, O_RDONLY);
	if (file == -1)
		exit(EXIT_FAILURE);
	if (dup2(file, STDIN_FILENO) == -1)
		exit(EXIT_FAILURE);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		exit(EXIT_FAILURE);
	close(fd[1]);
	close(file);
	if (!ft_exe_first_command(p))
		exit(EXIT_FAILURE);
	return (1);
}

int	ft_do_second_command(t_pipex *p, char *fl_2, int fd[2])
{
	int	file;

	close(fd[1]);
	file = open(fl_2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file == -1)
		exit(EXIT_FAILURE);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		exit(EXIT_FAILURE);
	if (dup2(file, STDOUT_FILENO) == -1)
		exit(EXIT_FAILURE);
	close(file);
	if (!ft_exe_second_command(p))
		exit(EXIT_FAILURE);
	return (1);
}

int	ft_do_pipex(t_pipex *p, char *fl_1, char *fl_2)
{
	int		fd[2];
	pid_t	pid;

	pipe(fd);
	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);
	else if (pid == 0)
	{
		if (!ft_do_second_command(p, fl_2, fd))
			exit(EXIT_FAILURE);
	}
	else
	{
		if (!ft_do_first_command(p, fl_1, fd))
			exit(EXIT_FAILURE);
	}
	return (1);
}
