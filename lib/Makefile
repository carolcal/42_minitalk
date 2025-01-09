# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 15:38:33 by cayamash          #+#    #+#              #
#    Updated: 2025/01/09 11:45:01 by cayamash         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = ft_isdigit.c ft_bzero.c ft_strlen.c ft_strlcpy.c ft_strlcat.c\
		ft_strdup.c ft_atoi.c ft_calloc.c ft_strjoin.c\
		ft_printf_utils.c ft_printf.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%o: %c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
