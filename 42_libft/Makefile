
HEADER	=	libft.h

CFILES	=	ft_isalpha.c\
			ft_isalnum.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_isprint.c\
			ft_strlen.c\
			ft_strlcpy.c\
			ft_strlcat.c

OFILES	=	$(CFILES:.c=.o)

CC	=	cc

CFLAGS	=	-Wall -Wextra -Werror

NAME	:=	libft.a

all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
