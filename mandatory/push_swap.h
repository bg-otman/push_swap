/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:24:48 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/16 15:55:32 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

t_list	*create_lst(char *av[]);
void	swap_a(t_list *stack_a);
void	swap_b(t_list *stack_b);
void	swap_ab(t_list *stack_a, t_list *stack_b);
void	ft_swap(t_list *stack);
void	push_a(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_b, t_list **stack_a);
void	pop(t_list **stack);
void    ft_push(t_list **stack_one, t_list **stack_two);
void	rotate_a(t_list **stack_a);
void	rotate_b(t_list **stack_b);
void	rotate_ab(t_list **stack_a, t_list **stack_b);
void    ft_rotate(t_list **stack);
void	reverse_rotate_a(t_list **stack_a);
void	reverse_rotate_b(t_list **stack_b);
void	reverse_rotate_ab(t_list **stack_a, t_list **stack_b);
void    reverse_rotate(t_list **stack);
void    free_arr(char **arr);
void	sort_three(t_list **stack);
void    sort_five(t_list **stack_a, t_list **stack_b);
void    parse_argument(char *arr[]);
void    check_double_and_sorted(int *sorted_arr, int size, t_list **stack_a);
void    bring_to_top(t_list **stack_a, int first, int last);
void    sort(t_list **stack_a, t_list **stack_b);
int		*sorted_version(t_list *stack_a);
int		get_in_range(t_list *stack_a, int range);
int		get_max_element(t_list *stack);
int		get_index(t_list *stack, int num);
int		get_chunk_size(int lst_size);
int		is_sorted(t_list *stack);
int     handle_empty_str(char **str);
char    *process_input(char *av[]);


#endif