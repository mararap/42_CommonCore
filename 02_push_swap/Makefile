
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
CFLAGS	=	-g -Wall -Wextra -Werror
RM		=	rm -f
AR		=	ar crs

# **************************************************************************** #
#                                   PATHS                                      #
# **************************************************************************** #

SRC_DIR			=		src
OBJ_DIR			=		obj
LIBFT_DIR		=		inc/libft
LIBFT			=		$(LIBFT_DIR)/libft.a

HEADER			=		src/

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

all: $(NAME)


$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -I ./inc/libft/ $(OBJS) -o $@ ./inc/libft/libft.a
	@echo "PUSH_SWAP executable successfully created."

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -I $(SRC_DIR) -c $< -o $@ inc/libft/libft.a

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
