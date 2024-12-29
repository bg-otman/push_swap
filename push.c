/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:33:23 by obouizi           #+#    #+#             */
/*   Updated: 2024/12/29 15:58:24 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pop(t_list **stack)
{
    t_list *new_head;

    new_head = (*stack)->next;
    free((*stack));
    (*stack) = new_head;
}

void push_a(t_list **stack_a, t_list **stack_b)
{
    t_list *node;
    
    if (!(*stack_b))
        return ;
    node = ft_lstnew((*stack_b)->num);
    if (!node)
        return ;
    pop(stack_b);
    ft_lstadd_front(stack_a, node);
    // ft_printf("pa\n");
}

void push_b(t_list **stack_b, t_list **stack_a)
{
    push_a(stack_b, stack_a);
    // ft_printf("pb\n");
}
