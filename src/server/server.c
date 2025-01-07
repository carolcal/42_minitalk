/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:55:36 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/07 18:36:28 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//if SIGUSR1: bit = 1
//if SIGUSR2: bit = 2

void	handler(int signo, siginfo_t *info, void *context);

int	main(void)
{
	pid_t pid = getpid();

	ft_printf("PID Server: %d\n", pid);

	while (1)
		pause();
	
	return (0);
}
