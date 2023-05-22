/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:50:56 by alvalope          #+#    #+#             */
/*   Updated: 2023/05/22 13:49:08 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	ft_do_pipex(t_pipex *p)
{
	//execve(p->path1, p->args1, 0);
	ft_free_all(p);
	return (1);
}

void	ft_leaks(void)
{
	system("leaks -q a.out");
}

int	main(int argc, char *argv[])
{
	t_pipex	p;

	atexit(ft_leaks);
	argc = 5;
	argv[1] = "origin.txt";
	argv[2] = "ls -l -a";
	argv[3] = "wc -w";
	argv[4] = "destin.txt";
	//p = (t_pipex *)ft_calloc(sizeof(t_pipex), 1);
	if (argc != 5)
		ft_printf("\nNúmero de parametros incorrecto\n.");
	else
	{
		if (!ft_read_file_p(argv[1]))
		{
			ft_printf("No existe el archivo %s\n", argv[1]);
			return (0);
		}
		if (!ft_check_first_command(&p, argv[2]))
		{
			ft_printf("No se reconoce el comando %s\n", argv[2]);
			return (0);
		}
		if (!ft_check_second_command(&p, argv[3]))
		{
			ft_printf("No se reconoce el comando %s\n", argv[3]);
			return (0);
		}
		ft_do_pipex(&p);
	}
	return (0);
}
