/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:35:27 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/16 11:46:19 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_rotate(t_list **stack)
{
    int temp;

    if (!stack || !(*stack))
        return ;
    temp = (*stack)->num;
    pop(stack);
    ft_lstadd_back(stack, ft_lstnew(temp));
}

void rotate_a(t_list **stack_a)
{
    if (!stack_a || !(*stack_a))
        return ;
    ft_rotate(stack_a);
    ft_putstr_fd("ra\n", 1);
}

void rotate_b(t_list **stack_b)
{
    if (!stack_b || !(*stack_b))
        return ;
    ft_rotate(stack_b);
    ft_putstr_fd("rb\n", 1);
}

void rotate_ab(t_list **stack_a, t_list **stack_b)
{
    if ((!stack_b || !(*stack_b)) || (!stack_a || !(*stack_a)))
        return ;
    ft_rotate(stack_a);
    ft_rotate(stack_b);
    ft_putstr_fd("rr\n", 1);
}
