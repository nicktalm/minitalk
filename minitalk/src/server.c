/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:18:22 by ntalmon           #+#    #+#             */
/*   Updated: 2024/02/14 15:36:47 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

// Diese Funktion liest Bit für Bit von signal
// setzt die entsprechenden Bits in i.
// Wenn ein vollständiges Byte empfangen wurde, wird
// das entsprechende Zeichen (ASCII-Code) ausgegeben und
// die Variablen zurückgesetzt, um das nächste Byte zu empfangen.

void	decode_char(int signal)
{
	static int	bit;
	static int	i;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	argv = 0;
	if (argc != 1)
	{
		ft_putendl_fd(M_SERVER, 2);
		ft_putendl_fd(M_SERVER2, 2);
		return (0);
	}
	pid = getpid();
	ft_printf(M_PID, pid);
	ft_putendl_fd(M_START, 1);
	while (argc == 1)
	{
		signal(SIGUSR1, decode_char);
		signal(SIGUSR2, decode_char);
		pause();
	}
	return (0);
}
