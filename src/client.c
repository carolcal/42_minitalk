/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:26:10 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/08 16:50:35 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_response = 0;

void response_handler(int signal)
{
	if (signal == SIGUSR1)
		g_response = 1;
}

void	send_message(int pid, char *message)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(message);
	while (i <= len)
	{
		j = 7;
		while (j >= 0)
		{
			if (message[i] >> j & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j--;
			while (!g_response)
				usleep(250);
			g_response = 0;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;

	if (argc != 3)
	{
		ft_printf("Execute client as follows: ./client [PID] [message]\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);

	signal(SIGUSR1, &response_handler);

	send_message(pid, argv[2]);

	return (0);
}
