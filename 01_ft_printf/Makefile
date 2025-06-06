# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marapovi <marapovi@student.42vienna.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/27 19:28:49 by marapovi          #+#    #+#              #
#    Updated: 2025/05/27 19:28:52 by marapovi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER	=	libftprintf.h

CFILES	=	ft_printf.c\
			ft_putchar.c\
			ft_putstr.c\
			ft_putnbr.c

OFILES	=	$(CFILES:.c=.o)

cc	=	cc

CFLAGS	=	-Wall -Wextra -Werror

NAME	:=	libftprintf.a

all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
