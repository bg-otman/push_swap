SRCS = push_swap.c printf/ft_putchar.c printf/ft_check_specifier.c printf/ft_strlen.c printf/ft_printf.c \
		printf/ft_valid_specifier.c printf/ft_putstr.c printf/ft_putnbr.c printf/ft_puthex.c printf/ft_putunsint.c \
		printf/ft_putadresse.c \
		libft/ft_lstnew.c libft/ft_lstlast.c libft/ft_lstadd_back.c libft/ft_lstadd_front.c libft/ft_lstclear.c \
		libft/ft_atoi.c libft/ft_lstsize.c \
		swap.c push.c rotate.c reverse_rotate.c sorted_version.c

OBJECTS=$(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = push_swap

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

clean :
	$(RM) $(OBJECTS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
.SECONDARY : $(OBJECTS)
