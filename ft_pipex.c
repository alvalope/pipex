/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:50:56 by alvalope          #+#    #+#             */
/*   Updated: 2023/05/25 22:20:43 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	main(int argc, char *argv[])
{
	t_pipex	p;

	/*argc = 5;
	argv[1] = "origi.txt";
	argv[2] = "grep hola";
	argv[3] = "awk \"'{count++} END {print count}'\"";
	argv[4] = "destiny.txt";*/
	if (argc != 5)
	{
		ft_printf("\nNúmero de parametros incorrecto.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		/*if (!ft_verify_file(argv[1]))
			exit(EXIT_FAILURE);*/
		if (!ft_check_first_command(&p, argv[2]))
			exit(EXIT_FAILURE);
		if (!ft_check_second_command(&p, argv[3]))
			exit(EXIT_FAILURE);
		if (!ft_do_pipex(&p, argv[1], argv[4]))
		{
			ft_free_all(&p);
			exit(EXIT_FAILURE);
		}
	}
	return (3);
}
