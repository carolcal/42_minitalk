/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:26:10 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/07 18:25:24 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(int argc, char **argv)
{
	if(argc != 3)
	{
		ft_printf("Executable Usage: ./client [PID] [message]\n");
		return (1);
	}
	while (argc--)
		ft_printf("%s\n", argv[argc]);
	return (0);
}
