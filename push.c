/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:33:23 by obouizi           #+#    #+#             */
/*   Updated: 2024/12/30 18:03:16 by obouizi          ###   ########.fr       */
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
    ft_push(stack_a, stack_b);
    ft_printf("pa\n");
}

void push_b(t_list **stack_b, t_list **stack_a)
{
    ft_push(stack_b, stack_a);
    ft_printf("pb\n");
}
