/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:55:36 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/08 16:48:36 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_message	g_message = {0, 0, 0};

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	//char	*msg;
	(void)context;
	g_message.c = g_message.c << 1;
	if (signal == SIGUSR1)
		g_message.c = g_message.c | 1;
	g_message.i++;
	if (g_message.i == 8)
	{
		if (g_message.c == '\0')
            write(1, "\n", 1); // Print a newline to separate messages
        else
            write(1, &g_message.c, 1);
			//ft_printf("%s", g_message.msg);
		// if (g_message.msg)
		// {
		// 	msg = ft_strjoin(g_message.msg, &g_message.c);
		// 	free(g_message.msg);
		// 	g_message.msg = msg;
		// }
		// else
		// 	g_message.msg = ft_strdup(&g_message.c);
		g_message.c = 0;
		g_message.i = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	signal_received;

	ft_printf("Welcome to Caroline Server *-*\n");
	ft_printf("PID Server: %d\n", getpid());

	signal_received.sa_sigaction = signal_handler;
	signal_received.sa_flags = SA_SIGINFO;

	sigaction(SIGUSR1, &signal_received, NULL);
	sigaction(SIGUSR2, &signal_received, NULL);

	while (1)
		pause();

	return (0);
}
