
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

NAME		:=	push_swap
CC			:=	cc

# C PreProcessor flags - only needed when compiling src files
CPPFLAGS	:=	-I inc -I libft

# C compiler flags - needed for compiling src files AND for linking
CFLAGS		:=	-Wall -Wextra -Werror

# Flags/Options passed to the linker
LDFLAGS		:=	-L libft

# Libraries to pass to the linker
LDLIBS 		:=	-lft

# set RM to remove directories and containing files recursiveley
RM			:=	rm -rf

# UNIX archive utility for creating static library
#	c to explicitly create the library and silence warning if its not there
#	r to replace existing symbols (functions) in the library and/or add new
#	s to create an index for the library so linker will find symbols quickly
AR			:=	ar crs


# **************************************************************************** #
#                                   PATHS                                      #
# **************************************************************************** #

OBJ_DIR			:=		obj
SRC_DIR			:=		src
LIBFT_DIR		:=		libft
LIBFT			:=		$(LIBFT_DIR)/libft.a

SRC				:=		main.c\
						ps_parsing.c\
						ps_stack_init.c\
						ps_stack_utils.c\
						ps_op_push.c\
						ps_op_swap.c\
						ps_op_rotate.c\
						ps_op_reverserotate.c\
						ps_sorting.c\
						ps_sorting_utils.c\
						ps_sorting_utils2.c\
						ps_error_handling.c


SRCS		:=			$(addprefix $(SRC_DIR)/,$(SRC))
OBJS		:=			$(patsubst %.c,$(OBJ_DIR)/%.o,$(notdir $(SRC)))

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: $(LIBFT) $(NAME)

# create libft.a -> --no-print-directory to silence make's 'entering dir...'
$(LIBFT):
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)
	@echo "     ✅ LIBFT library successfully created."

# tell make where to look for %.c files (needed if .c-files in different dirs)
vpath %.c $(SRC_DIR) ..

# Compilation: create OBJ_DIR if missing, then compile c-files to o-files
# and stop (-c)
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# Linking
$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)
	@echo "     ✅ PUSH_SWAP executable successfully created."

clean:
	@$(RM) $(OBJ_DIR)
	@echo "     🧹 PUSH_SWAP	= clean."
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean
	@echo "     🧹 LIBFT 		= clean." 


fclean: clean
	@$(RM) $(NAME)
	@echo "     🧹 PUSH_SWAP executable removed."
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean
	@echo "     🧹 LIBFT library removed."

re: fclean all

.PHONY: all clean fclean re
