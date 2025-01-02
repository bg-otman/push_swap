/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:24:48 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/02 09:13:45 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "printf/libftprintf.h"
# include "libft/libft.h"

void swap_a(t_list *stack_a);
void swap_b(t_list *stack_b);
void swap_ab(t_list *stack_a, t_list *stack_b);
void push_a(t_list **stack_a, t_list **stack_b);
void push_b(t_list **stack_b, t_list **stack_a);
void pop(t_list **stack);
void rotate_a(t_list **stack_a);
void rotate_b(t_list **stack_b);
void rotate_ab(t_list **stack_a, t_list **stack_b);
void reverse_rotate_a(t_list **stack_a);
void reverse_rotate_b(t_list **stack_b);
void reverse_rotate_ab(t_list **stack_a, t_list **stack_b);


#endif