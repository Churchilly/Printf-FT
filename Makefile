NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra
AR = ar -rcs
RM = rm -rf

SRCS =	ft_printf.c \
		ft_printf_utils.c

OBJ = $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re