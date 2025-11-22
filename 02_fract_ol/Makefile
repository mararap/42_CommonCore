# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/16 17:55:51 by marapovi          #+#    #+#              #
#    Updated: 2025/11/22 16:32:50 by marapovi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# **************************************************************************** #
#                                 VARIABLES                                    #
# **************************************************************************** #

NAME		:=	fractol
CC			:=	cc

# C PreProcessor flags - exclusively needed when compiling src files
CPPFLAGS	:=	-I inc -I libft

# C compiler flags - needed for compiling src files AND for linking
CFLAGS		:=	-Wall -Wextra -Werror -O2 -march=native

# Flags/Options passed to the linker
LDFLAGS		:=	-L libft

# Libraries to pass to the linker
LDLIBS 		:=	-lft -lmlx -lX11 -lXext -lm

# set RM to remove directories and containing files recursiveley
RM			:=	rm -rf

# UNIX archive utility for creating static library
#	c to explicitly create the library and silence warning if its not there
#	r to replace existing symbols (functions) in the library and/or add new
#	s to create an index for the library so linker will find symbols quickly
#A	R		:=	ar crs


# **************************************************************************** #
#                                   PATHS                                      #
# **************************************************************************** #

OBJ_DIR			:=		obj
SRC_DIR			:=		src
LIBFT_DIR		:=		libft
LIBFT			:=		$(LIBFT_DIR)/libft.a

SRC				:=		fo_main.c\
						fo_atof.c\
						fo_create.c\
						fo_handle_colors.c\
						fo_handle_errors.c\
						fo_handle_events.c\
						fo_init.c\
						fo_render.c

SRC				:=		$(addprefix $(SRC_DIR)/,$(SRC))
#OBJ			:=		$(addprefix $(OBJ_DIR)/,$(OBJ))
OBJ				:=		$(patsubst %.c,$(OBJ_DIR)/%.o,$(notdir $(SRC)))

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)
	@echo "     ✅ LIBFT library successfully created."

#vpath %.c $(SRC_DIR) ..

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) $(LDLIBS) -o $(NAME)
	@echo "     ✅ FRACTOL executable successfully created."

clean:
	@$(RM) $(OBJ_DIR)
	@echo "     🧹 FRACTOL	= clean."
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean
	@echo "     🧹 LIBFT 	= clean."

fclean: clean
	@$(RM) $(NAME)
	@echo "     🧹 FRACTOL executable removed."
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean
	@echo "     🧹 LIBFT library removed."

re: fclean all

.PHONY: all clean fclean re