# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marapovi <marapovi@student.42vienna.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/11 19:06:07 by marapovi          #+#    #+#              #
#    Updated: 2025/08/11 19:06:14 by marapovi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

# Directories
SRC_DIR = src
INC_DIR = include
LIBFT_DIR = libft

# Header
HEADER = $(INC_DIR/push_swap.h)

# Files
SRC = parsing.c\

OBJ = $(addprefix $(SRC_DIR)/, $(SRC:.c=.o))

# Compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR)

# Library
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

