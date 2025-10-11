
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
CFLAGS	=	-Wall -Wextra -Werror -I libft/inc
HEADER	=	$(INC_DIR)/push_swap.h
RM		=	rm -f
AR		=	ar crs

# **************************************************************************** #
#                                   PATHS                                      #
# **************************************************************************** #

SRC_DIR			=		src/
INC_DIR			=		inc/
OBJ_DIR			=		obj/
LIBFT_DIR		=		libft/
LIBFT			=		$(LIBFT_DIR)/libft.a

SRC				=		src/main.c\
						src/ps_isvalid.c\
						src/ps_atol_check.c\
						src/ps_parse_one.c\
						src/ps_parse_multi.c\
						src/ps_free_str_arr.c\


OBJS = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o) | $(OBJ_DIR)

INCLUDE 		= 		-L ./libft -lft

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: $(NAME)

$(NAME):  $(OBJS)
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INCLUDE) $Iinc
	@echo "PUSH_SWAP executable successfully created."

clean:
	@$(RM) $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "PUSH_SWAP Object files removed."

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "PUSH_SWAP executable removed."

re: fclean all

.PHONY: all clean fclean re
