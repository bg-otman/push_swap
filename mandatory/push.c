/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:33:23 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/16 11:44:49 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pop(t_list **stack)
{
    t_list *new_head;
    
    if (!stack || !(*stack))
        return ;
    new_head = (*stack)->next;
    free((*stack));
    (*stack) = new_head;
}

void    ft_push(t_list **stack_one, t_list **stack_two)
{
    t_list *node;
    
    if (!(*stack_two))
        return ;
    node = ft_lstnew((*stack_two)->num);
    if (!node)
        return ;
    pop(stack_two);
    ft_lstadd_front(stack_one, node);
}


void push_a(t_list **stack_a, t_list **stack_b)
{
    if (!stack_b || !(*stack_b))
        return ;
    ft_push(stack_a, stack_b);
    ft_putstr_fd("pa\n", 1);
}

void push_b(t_list **stack_b, t_list **stack_a)
{
    if (!stack_a || !(*stack_a))
        return ;
    ft_push(stack_b, stack_a);
    ft_putstr_fd("pb\n", 1);
}
