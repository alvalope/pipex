/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:50:56 by alvalope          #+#    #+#             */
/*   Updated: 2023/05/26 13:09:54 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	main(int argc, char *argv[])
{
	t_pipex	p;

	if (argc != 5)
	{
		ft_printf("\nNúmero de parametros incorrecto.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		ft_check_first_command(&p, argv[2]);
		ft_check_second_command(&p, argv[3]);
		if (!ft_do_pipex(&p, argv[1], argv[4]))
		{
			ft_free_all(&p);
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}
