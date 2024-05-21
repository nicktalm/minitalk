/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:27:20 by ntalmon           #+#    #+#             */
/*   Updated: 2024/02/14 15:54:56 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	convert_and_send(int server_pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (0x01 << bit))
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	server_pid;

	i = 0;
	server_pid = 0;
	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		if (server_pid <= 0)
			return (ft_putendl_fd(M_ERROR, 2), 0);
		while (argv[2][i])
		{
			convert_and_send(server_pid, argv[2][i]);
			i++;
		}
		convert_and_send(server_pid, '\n');
	}
	else
	{
		ft_putendl_fd(M_ERROR, 2);
		ft_putendl_fd(M_MESSAGE, 2);
		ft_putendl_fd(M_EXAMPLE, 2);
		ft_putendl_fd(M_EXAMPLE2, 2);
	}
	return (0);
}
