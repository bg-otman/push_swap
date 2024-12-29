/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:35:27 by obouizi           #+#    #+#             */
/*   Updated: 2024/12/29 16:18:06 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate_a(t_list **stack_a)
{
    int temp;
    t_list *last_node;

    last_node = ft_lstlast((*stack_a));
    temp = (*stack_a)->num;
    (*stack_a)->num = last_node->num;
    last_node->num = temp;
    // ft_printf("ra\n");
}

void rotate_b(t_list **stack_b)
{
    rotate_a(stack_b);
    // ft_printf("rb\n");
}

void rotate_ab(t_list **stack_a, t_list **stack_b)
{
    rotate_a(stack_a);
    rotate_b(stack_b);
    // ft_printf("rr\n");
}
