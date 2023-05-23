/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:50:56 by alvalope          #+#    #+#             */
/*   Updated: 2023/05/23 13:47:44 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

/*void	ft_leaks(void)
{
	system("leaks -q a.out");
}*/

int	main(int argc, char *argv[])
{
	t_pipex	p;

	/*atexit(ft_leaks);
	argc = 5;
	argv[1] = "origin.txt";
	argv[2] = "grep e";
	argv[3] = "wc -w";
	argv[4] = "destiny.txt";*/
	if (argc != 5)
		ft_printf("\nNúmero de parametros incorrecto.\n");
	else
	{
		if (!ft_verify_file(argv[1]))
			exit(EXIT_FAILURE);
		if (!ft_check_first_command(&p, argv[2]))
			exit(EXIT_FAILURE);
		if (!ft_check_second_command(&p, argv[3]))
			exit(EXIT_FAILURE);
		if (!ft_do_pipex(&p, argv[1], argv[4]))
			ft_free_all(&p);
	}
	return (0);
}
