NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra -fPIE
AR = ar -rcs
RM = rm -rf

SRCS =	ft_printf.c			\
		ft_flags.c			\
		ft_print_char.c		\
		ft_print_str.c		\
		ft_print_int.c		\
		ft_print_uint.c		\
		ft_print_hex.c		\
		ft_print_address.c	\

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