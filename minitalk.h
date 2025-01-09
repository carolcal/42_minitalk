/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:51:21 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/09 12:19:00 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "lib/libft.h"

typedef struct s_message
{
	char	c;
	int		i;
	char	*msg;
}	t_message;

#endif
