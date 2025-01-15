SRCS = push_swap.c printf/ft_putchar.c printf/ft_check_specifier.c printf/ft_printf.c \
		printf/ft_valid_specifier.c printf/ft_putstr.c printf/ft_putnbr.c printf/ft_puthex.c printf/ft_putunsint.c \
		printf/ft_putadresse.c \
		libft/ft_lstnew.c libft/ft_lstlast.c libft/ft_lstadd_back.c libft/ft_lstadd_front.c libft/ft_lstclear.c libft/ft_strdup.c \
		libft/ft_atoi.c libft/ft_lstsize.c libft/ft_split.c libft/ft_calloc.c libft/ft_strlen.c libft/ft_substr.c libft/ft_bzero.c \
		libft/ft_strjoin.c libft/ft_memcpy.c libft/ft_isdigit.c libft/ft_putstr_fd.c \
		create_lst.c swap.c push.c rotate.c reverse_rotate.c sorted_version.c small_sort.c \
		get_range_and_chunk.c get_max_and_index.c is_sorted.c handle_empty_str.c process_input.c free_arr.c parse_arguments.c \
		check_double.c bring_to_top.c \

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
