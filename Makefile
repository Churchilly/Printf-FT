NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra
AR = ar -rcs
RM = rm -rf

SRCS =	ft_printf.c			\
		ft_preprocess.c		\
		ft_add_toprint.c	\
		ft_add_char.c		\
		ft_add_str.c		\
		ft_add_int.c		\
		ft_add_uint.c		\
		ft_add_hex.c		\
		ft_add_address.c	\

OBJ = $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: = all clean fclean re