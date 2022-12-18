# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmiseiki <vmiseiki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/13 16:40:53 by vmiseiki          #+#    #+#              #
#    Updated: 2022/12/18 16:54:45 by vmiseiki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Color codes
RESET	= \033[0m
GREEN	= \033[32m
YELLOW	= \033[33m
BLUE	= \033[34m

# Name of the program
NAME = libft.a

# Compilation flags
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

%.o : %.c 
	@cc -O2 -w -DSTRINGPUTX11   -c -o $@ $<

SRC = ft_memset.c\
ft_strlen.c\
ft_atoi.c\
ft_putchar_fd.c\
ft_putnbr_fd.c\
ft_itoa.c\
ft_strdup.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar -r $(NAME) $(OBJ)
	@ranlib $(NAME)
	
clean:
	@rm -f *.o

fclean: clean
	@rm -f *.a

re: fclean all

.PHONY: all clean fclean re bonus