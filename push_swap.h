/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:24:48 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/15 22:06:14 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "printf/libftprintf.h"
# include "libft/libft.h"

t_list	*create_lst(char *av[]);
void	swap_a(t_list *stack_a);
void	swap_b(t_list *stack_b);
void	swap_ab(t_list *stack_a, t_list *stack_b);
void	ss_or_swap_b(t_list *stack_a, t_list *stack_b);
void	push_a(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_b, t_list **stack_a);
void	pop(t_list **stack);
void	rotate_a(t_list **stack_a);
void	rotate_b(t_list **stack_b);
void	rotate_ab(t_list **stack_a, t_list **stack_b);
void	reverse_rotate_a(t_list **stack_a);
void	reverse_rotate_b(t_list **stack_b);
void	reverse_rotate_ab(t_list **stack_a, t_list **stack_b);
void    free_arr(char **arr);
void	sort_three(t_list **stack);
void    sort_five(t_list **stack_a, t_list **stack_b);
void	push_and_sort_b(t_list **stack_a, t_list **stack_b);
void    parse_argument(char *arr[]);
void    check_double_and_sorted(int *sorted_arr, int size, t_list **stack_a);
void    bring_to_top(t_list **stack_a, int first, int last);
int		*sorted_version(t_list *stack_a);
int		get_in_range(t_list *stack_a, int range);
int		get_max_element(t_list *stack);
int		get_index(t_list *stack, int num);
int		get_chunk_size(int lst_size);
int		is_sorted(t_list *stack);
int     handle_empty_str(char **str);
char    *process_input(char *av[]);


#endif