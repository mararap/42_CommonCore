# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marapovi <marapovi@student.42vienna.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/25 13:28:32 by marapovi          #+#    #+#              #
#    Updated: 2025/04/25 13:28:39 by marapovi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#include <libft.h>

NAME := libft.a


libft: libft.h	ft_isalpha.o
	ar	rcs	libft.h	ft_isalpha.o -o libft

ft_isalpha.o: ft_isalpha.c
	cc -Wall -Wextra -Werror ft_isalpha.c -o ft_isalpha.o

clean:
	rm	-f	ft_isalpha.o

	

	

