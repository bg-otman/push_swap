/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:24:48 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/14 19:00:33 by obouizi          ###   ########.fr       */
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
int		*sorted_version(t_list *stack_a);
void	sort_three(t_list **stack);
void    sort_five(t_list **stack_a, t_list **stack_b);
void	push_and_sort_b(t_list **stack_a, t_list **stack_b);
int		get_in_range(t_list *stack_a, int range);
int		get_max_element(t_list *stack);
int		get_index(t_list *stack, int num);
int		get_chunk_size(int lst_size);
int		is_sorted(t_list *stack);


#endif