/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:52:45 by alvalope          #+#    #+#             */
/*   Updated: 2023/05/22 13:39:18 by alvalope         ###   ########.fr       */
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

int		ft_count_lines(int file);
int		ft_read_file_p(char *archive);

//void	ft_free_lines(t_pipex *p);
void	ft_free_all(t_pipex *p);
void	ft_free_path_com(t_pipex *p, int n);
void	ft_free_com(char **com);


int		ft_check_first_command(t_pipex *p, char *command);
int		ft_check_second_command(t_pipex *p, char *command);

int		main(int argc, char *argv[]);

#endif