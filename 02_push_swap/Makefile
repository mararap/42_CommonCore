
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/11 19:06:07 by marapovi          #+#    #+#              #
#    Updated: 2025/10/10 18:00:00 by marapovi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
CC		=	cc
CFLAGS	=	-g -Wall -Wextra -Werror -I inc/libft
RM		=	rm -f
AR		=	ar crs

# **************************************************************************** #
#                                   PATHS                                      #
# **************************************************************************** #

SRC_DIR			=		src
OBJ_DIR			=		obj
LIBFT_DIR		=		inc/libft
LIBFT			=		$(LIBFT_DIR)/libft.a

SRC				=		../main.c\
						ps_parsing.c\
						ps_atol_check.c\
						ps_utils.c

SRCS		=			$(addprefix $(SRC_DIR)/, $(SRC))
OBJS		=			$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)
	@echo "LIBFT library successfully created."

# Compilation
$(OBJ_DIR)/main.o: main.c
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

#$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
#	@$(CC) $(CFLAGS) -c $< -o $@

# Linking
$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "PUSH_SWAP executable successfully created."

clean:
	@$(RM) $(OBJS)
	@echo "PUSH_SWAP OBJ_DIR is clean."
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean
	@echo "LIBFT %.o-files removed." 


fclean: clean
	@$(RM) $(NAME)
	@echo "PUSH_SWAP root is clean."
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean
	@echo "LIBFT %.a-file removed."

re: fclean all

.PHONY: all clean fclean re
