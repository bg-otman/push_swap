/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:37:07 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/16 11:45:47 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    reverse_rotate(t_list **stack)
{
    int temp;
    t_list *node;
    t_list *before_last;
    
    if (!stack || !(*stack))
        return ;
    temp = ft_lstlast(*stack)->num;
    ft_lstadd_front(stack, ft_lstnew(temp));
    node = *stack;
    while (node->next)
    {
        before_last = node;
        node = node->next;
    }
    free(node);
    before_last->next = NULL;
}

void reverse_rotate_a(t_list **stack_a)
{
    if (!stack_a || !(*stack_a))
        return ;
    reverse_rotate(stack_a);
    ft_putstr_fd("rra\n", 1);
}

void reverse_rotate_b(t_list **stack_b)
{
    if (!stack_b || !(*stack_b))
        return ;
    reverse_rotate(stack_b);
    ft_putstr_fd("rrb\n", 1);
}

void reverse_rotate_ab(t_list **stack_a, t_list **stack_b)
{
    if ((!stack_b || !(*stack_b)) || (!stack_a || !(*stack_a)))
        return ;
    reverse_rotate(stack_a);
    reverse_rotate(stack_b);
    ft_putstr_fd("rrr\n", 1);
}
