/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:52:45 by alvalope          #+#    #+#             */
/*   Updated: 2023/05/26 12:20:14 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include "libftplus/libft.h"
# include <fcntl.h>
# include <string.h>
# include <errno.h>

typedef struct pipex
{
	char	**archive_lines;
	int		lines;
	char	*path1;
	char	*path2;
	char	**arg1;
	char	**arg2;
	int		command_not_found;
}	t_pipex;

void	ft_free_all(t_pipex *p);
void	ft_free_path_com(t_pipex *p, int n);

char	**ft_split_quote(char const *s, char c);

void	ft_check_first_command(t_pipex *p, char *command);
void	ft_check_second_command(t_pipex *p, char *command);

int		ft_do_first_command(t_pipex *p, char *fl_1, int fd[2]);
int		ft_do_second_command(t_pipex *p, char *fl_2, int fd[2]);
int		ft_do_pipex(t_pipex *p, char *fl_1, char *fl_2);

int		main(int argc, char *argv[]);

#endif