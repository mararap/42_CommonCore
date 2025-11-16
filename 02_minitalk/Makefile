
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

NAME_CLIENT		:=		client
NAME_SERVER		:=		server
CC				:=		cc
CFLAGS			:=		-Wall -Wextra -Werror
RM				:=		rm -rf
AR				:=		ar crs

# **************************************************************************** #
#                                   PATHS                                      #
# **************************************************************************** #

SRC_DIR			:=		src
OBJ_DIR			:=		obj
INC_DIR			:=		inc
LIBFT_DIR		:=		libft
INCLUDES		:=		-I $(INC_DIR) -I $(LIBFT_DIR)
LIBFT			:=		$(LIBFT_DIR)/libft.a

# List of source files
SRCS_CLIENT		:=		mt_client.c	mt_atol.c mt_client_utils.c
SRCS_SERVER		:=		mt_server.c

# Target: tell the Makefile where to find .c-files and where to put .o-files
OBJS_CLIENT		:=		$(addprefix $(OBJ_DIR)/,$(SRCS_CLIENT:.c=.o))
OBJS_SERVER		:=		$(addprefix $(OBJ_DIR)/,$(SRCS_SERVER:.c=.o))

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: $(NAME_CLIENT) $(NAME_SERVER)

$(LIBFT):
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)
	@echo "LIBFT library successfully created."

# Compile/Pattern Rule: compiles *.c-files to *.o-files, then stops (-c),
# so that it's possible to link the *.o-files to two seperate
# executables (client and server)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Linking client
$(NAME_CLIENT): $(OBJS_CLIENT) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS_CLIENT) -L $(LIBFT_DIR) -lft -o $(NAME_CLIENT)
	@echo "CLIENT executable successfully created."

# Linking server
$(NAME_SERVER): $(OBJS_SERVER) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS_SERVER) -L $(LIBFT_DIR) -lft -o $(NAME_SERVER)
	@echo "SERVER executable successfully created."

clean:
	@$(RM) $(OBJ_DIR)
	@echo "MINITALK OBJ_DIR removed."
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean
	@echo "LIBFT %.o-files removed." 


fclean: clean
	@$(RM) $(NAME_CLIENT) $(NAME_SERVER)
	@echo "MINITALK executables removed."
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean
	@echo "LIBFT %.a-file removed."

re: fclean all

.PHONY: all clean fclean re
