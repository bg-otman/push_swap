SRCS = libft/ft_lstnew.c libft/ft_lstlast.c libft/ft_lstadd_back.c libft/ft_lstadd_front.c libft/ft_lstclear.c libft/ft_strdup.c \
		libft/ft_atoi.c libft/ft_lstsize.c libft/ft_split.c libft/ft_calloc.c libft/ft_strlen.c libft/ft_substr.c libft/ft_bzero.c \
		libft/ft_strjoin.c libft/ft_memcpy.c libft/ft_isdigit.c libft/ft_putstr_fd.c libft/ft_strcmp.c \
		mandatory/create_lst.c mandatory/swap.c mandatory/push.c mandatory/rotate.c mandatory/reverse_rotate.c mandatory/sorted_version.c mandatory/small_sort.c \
		mandatory/get_range_and_chunk.c mandatory/get_max_and_index.c mandatory/is_sorted.c mandatory/handle_empty_str.c mandatory/process_input.c mandatory/free_arr.c mandatory/parse_arguments.c \
		mandatory/check_double.c mandatory/bring_to_top.c mandatory/sort.c mandatory/main.c

SRCS_BNS = libft/ft_lstnew.c libft/ft_lstlast.c libft/ft_lstadd_back.c libft/ft_lstadd_front.c libft/ft_lstclear.c libft/ft_strdup.c \
		libft/ft_atoi.c libft/ft_lstsize.c libft/ft_split.c libft/ft_calloc.c libft/ft_strlen.c libft/ft_substr.c libft/ft_bzero.c \
		libft/ft_strjoin.c libft/ft_memcpy.c libft/ft_isdigit.c libft/ft_putstr_fd.c libft/ft_strcmp.c \
		mandatory/create_lst.c mandatory/swap.c mandatory/push.c mandatory/rotate.c mandatory/reverse_rotate.c mandatory/sorted_version.c mandatory/small_sort.c \
		mandatory/get_range_and_chunk.c mandatory/get_max_and_index.c mandatory/is_sorted.c mandatory/handle_empty_str.c mandatory/process_input.c mandatory/free_arr.c mandatory/parse_arguments.c \
		mandatory/check_double.c mandatory/bring_to_top.c mandatory/sort.c \
		bonus/get_next_line/get_next_line.c bonus/get_next_line/get_next_line_utils.c bonus/checker_bonus.c bonus/swap_bonus.c bonus/rotate_bonus.c bonus/push_bonus.c bonus/reverse_rotate_bonus.c

OBJ=$(SRCS:.c=.o)
OBJ_BNS=$(SRCS_BNS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = push_swap
NAME_BNS = checker

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus : $(NAME_BNS)

$(NAME_BNS) : $(OBJ_BNS)
	$(CC) $(CFLAGS) $(OBJ_BNS) -o $(NAME_BNS)

clean :
	$(RM) $(OBJ) $(OBJ_BNS)

fclean : clean
	$(RM) $(NAME) $(NAME_BNS)

re : fclean all

.PHONY : all clean fclean re
# .SECONDARY : $(OBJ) $(OBJ_BNS)
