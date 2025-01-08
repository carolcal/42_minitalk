/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:26:10 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/08 11:28:51 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(int pid, char *message)
{
	int	i;
	int	j;
	int	bit;

	i = 0;
	while (message[i] != '\0')
	{
		j = 7;
		while (j >= 0)
		{
			bit = (message[i] >> j & 1);
			if (bit == 0)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(50);
			j--;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*message;

	if (argc != 3)
	{
		ft_printf("Execute client as follows: ./client [PID] [message]\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	message = ft_strdup(argv[2]);

	send_message(pid, message);

	return (0);
}
