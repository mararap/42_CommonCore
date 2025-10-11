# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/25 12:39:13 by marapovi          #+#    #+#              #
#    Updated: 2025/10/11 16:00:26 by marapovi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -Iinc
HEADER		=	libft.h
AR			=	ar rcs
RM			=	rm -f

# **************************************************************************** #
#                                   PATHS                                      #
# **************************************************************************** #

SRC_DIR		= 	src
OBJ_DIR		=	obj
INC_DIR		=	inc

CFILES		=	ft_isalpha.c\
				ft_isalnum.c\
				ft_isascii.c\
				ft_isdigit.c\
				ft_isprint.c\
				ft_strlen.c\
				ft_strlcpy.c\
				ft_strlcat.c\
				ft_strncmp.c\
				ft_memset.c\
				ft_bzero.c\
				ft_toupper.c\
				ft_tolower.c\
				ft_strnstr.c\
				ft_strchr.c\
				ft_strrchr.c\
				ft_memchr.c\
				ft_memcmp.c\
				ft_memcpy.c\
				ft_memmove.c\
				ft_calloc.c\
				ft_putchar_fd.c\
				ft_putstr_fd.c\
				ft_putendl_fd.c\
				ft_putnbr_fd.c\
				ft_strdup.c\
				ft_atol.c\
				ft_substr.c\
				ft_strmapi.c\
				ft_striteri.c\
				ft_strjoin.c\
				ft_strtrim.c\
				ft_itoa.c\
				ft_split.c\
				ft_printf.c\
				ft_putchar.c\
				ft_putstr.c\
				ft_putint.c\
				ft_putusint.c\
				ft_puthex.c\
				ft_putptr.c\
				get_next_line.c\
				ft_is_doub.c\
				ft_is_space.c\
				ft_is_digit.c\
				ft_atoi_base.c\
				ft_lcm.c\
				ft_gcd.c\
				ft_max.c\
				ft_lookup.c\
				ft_error_exit.c

SRC_FILES	=	$(addprefix $(SRC_DIR)/, $(SRC))

OBJ			=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@echo "LIBFT successfully created."

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER) | $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -0 $@
	@echo "LIBFT - Compiling: $<"

clean:
	@$(RM) $(OBJ)
	@echo "LIBFT Object files removed."

fclean: clean
	@$(RM) $(NAME)
	@echo "LIBFT Library removed."

re: fclean all

.PHONY: all clean fclean re
