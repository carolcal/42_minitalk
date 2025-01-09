/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:55:36 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/09 12:19:59 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_message	g_message = {0, 0, 0};

void	create_message(void)
{
	char	*msg;

	if (g_message.msg)
	{
		msg = ft_strjoin(g_message.msg, &g_message.c);
		if (msg == NULL)
		{
			free(g_message.msg);
			exit(EXIT_FAILURE);
		}
		free(g_message.msg);
		g_message.msg = msg;
	}
	else
	{
		g_message.msg = ft_strdup(&g_message.c);
		if (!g_message.msg)
			exit(EXIT_FAILURE);
	}
}

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	(void)context;
	g_message.c = g_message.c << 1;
	if (signal == SIGUSR1)
		g_message.c = g_message.c | 1;
	g_message.i++;
	if (g_message.i == 8)
	{
		if (g_message.c == '\0')
		{
			if (g_message.msg)
				ft_printf("%s\n", g_message.msg);
			else
				ft_printf("\n");
			free(g_message.msg);
			g_message.msg = NULL;
		}
		else
			create_message();
		g_message.c = 0;
		g_message.i = 0;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		exit(EXIT_FAILURE);
}

int	main(void)
{
	struct sigaction	signal_received;

	ft_printf("Welcome to Caroline Server *-*\n");
	ft_printf("PID Server: %d\n", getpid());
	signal_received.sa_sigaction = signal_handler;
	signal_received.sa_flags = SA_SIGINFO;
	sigemptyset(&signal_received.sa_mask);
	sigaction(SIGUSR1, &signal_received, NULL);
	sigaction(SIGUSR2, &signal_received, NULL);
	while (1)
		pause();
	return (0);
}
