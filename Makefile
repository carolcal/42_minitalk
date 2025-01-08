# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 16:20:34 by cayamash          #+#    #+#              #
#    Updated: 2025/01/08 12:20:03 by cayamash         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Name of the program of the library
SERVER = server
CLIENT = client

#Compilers and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

#Directories
SRCS = src
INCLUDES = -I lib/ -I src/ -I .

# Source files and object files
SRC_CLIENT = $(SRCS)/client.c
SRC_SERVER = $(SRCS)/server.c
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)

#Library
LIBFT = lib/libft.a

#Rules
all: $(LIBFT) $(CLIENT) $(SERVER)

#Client Executable
$(CLIENT): $(OBJ_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIBFT) -o $(CLIENT)

#Server Executable
$(SERVER): $(OBJ_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIBFT) -o $(SERVER)

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compile the library
$(LIBFT):
	@make -C lib
	@echo "Library Compiled."

#Clean object files
clean: 
	@make -C lib clean
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER)

#Clean all generated files
fclean: clean
	@make -C lib fclean
	rm -f $(SERVER) $(CLIENT)

#Recompile everything
re: fclean all

.PHONY: all clean fclean re

