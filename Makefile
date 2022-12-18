# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmiseiki <vmiseiki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/21 21:32:11 by vmiseiki          #+#    #+#              #
#    Updated: 2022/12/18 17:31:28 by vmiseiki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Color codes
RESET	= \033[0m
GREEN	= \033[32m
YELLOW	= \033[33m
BLUE	= \033[34m

# Name of the program
SERVER_NAME = server
CLIENT_NAME = client

# Compilation flags
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

# Folders
LIBFT_DIR = ./libft/

# Source files
SERVER_SRC = server.c
CLIENT_SRC = client.c

#lib targets
LIB_FT = ./libft/libft.a

# Compilation rules
all: ${LIB_FT} ${SERVER_NAME} ${CLIENT_NAME}

${SERVER_NAME}: ${SERVER_SRC}
	@echo "$(YELLOW)----- Compiling. Please Wait! -----$(RESET)"
	@$(CC) $(CFLAGS) $(LIB_FT) -o $@ $^

${CLIENT_NAME}: ${CLIENT_SRC}
	@$(CC) $(CFLAGS) $(LIB_FT) -o $@ $^
	@echo "$(GREEN)----- Compilation completed!  -----$(RESET)"

${LIB_FT}:	
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@rm -f $(SERVER_NAME)
	@rm -f $(CLIENT_NAME)
	@rm -f $(LIBFT_DIR)*.o

fclean: clean
	@rm -f $(LIBFT_DIR)*.a

re: fclean all

.PHONY: all clean fclean re
