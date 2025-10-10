
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
CFLAGS	=	-Wall -Wextra -Werror -Iinc -Ilibft/inc
HEADER	=	$(INC_DIR)/push_swap.h
RM		=	rm -f

# **************************************************************************** #
#                                   PATHS                                      #
# **************************************************************************** #

SRC_DIR			=		src
INC_DIR			=		inc
OBJ_DIR			=		obj
LIBFT			=		libft

SRC				=		src/main.c\
						src/ps_isvalid.c\
						src/ps_atol_check.c\
						src/ps_parse_one.c\
						src/ps_parse_multi.c\
						src/ps_free_str_arr.c\


OBJS = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "Success!!"

$(LIBFT):
	@$(MAKE) -C $(LIBFT)
	@echo "Libft successfully created!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling: $<"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "Object files removed."


fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "Libraries removed."

re: fclean all

.PHONY: all clean fclean re
