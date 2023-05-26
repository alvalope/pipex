/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:52:45 by alvalope          #+#    #+#             */
/*   Updated: 2023/05/26 09:48:43 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include "libftplus/libft.h"
# include <fcntl.h>

typedef struct pipex
{
	char	**archive_lines;
	int		lines;
	char	*path1;
	char	*path2;
	char	**args1;
	char	**args2;
}	t_pipex;

int		ft_verify_file(char *archive);
void	ft_free_all(t_pipex *p);
void	ft_free_path_com(t_pipex *p, int n);

char	**ft_split_quote(char const *s, char c);

int		ft_check_first_command(t_pipex *p, char *command);
int		ft_check_second_command(t_pipex *p, char *command);

int		ft_exe_first_command(t_pipex *p);
int		ft_exe_second_command(t_pipex *p);
int		ft_do_first_command(t_pipex *p, char *fl_1, int fd[2]);
int		ft_do_second_command(t_pipex *p, char *fl_2, int fd[2]);
int		ft_do_pipex(t_pipex *p, char *fl_1, char *fl_2);

int		main(int argc, char *argv[]);

#endif