
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/11 19:06:07 by marapovi          #+#    #+#              #
#    Updated: 2025/10/10 18:00:00 by marapovi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
CC		=	cc
CFLAGS	=	-g -Wall -Wextra -Werror -Iinc -Ilibft/inc
RM		=	rm -f
AR		=	ar crs

# **************************************************************************** #
#                                   PATHS                                      #
# **************************************************************************** #

SRC_DIR			=		src
INC_DIR			=		inc
OBJ_DIR			=		obj
LIBFT_DIR		=		libft
LIBFT			=		$(LIBFT_DIR)/libft.a

SRC				=		main.c\
						ps_isvalid.c\
						ps_atol_check.c\
						ps_parse_one.c\
						ps_parse_multi.c\
						ps_free_str_arr.c\


OBJ			=	$(SRC:.c=.o)

SRC_FILES	=	$(addprefix $(SRC_DIR)/, $(SRC))

OBJS		=	$(addprefix $(OBJ_DIR)/, $(OBJ))


# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: libs $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@
	@echo "PUSH_SWAP executable successfully created."

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

libs:
	@make -C $(LIBFT_DIR)

clean:
	@$(RM) $(OBJ)
	@make -C $(LIBFT_DIR) clean
	@echo "PUSH_SWAP Object files removed."

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "PUSH_SWAP executable removed."

re: fclean all

.PHONY: all clean fclean re
