/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:30:37 by obouizi           #+#    #+#             */
/*   Updated: 2024/12/29 12:32:12 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_a(t_list *stack_a)
{
    int temp;
    
    if (!stack_a || !stack_a->next)
        return ;
    temp = stack_a->num;
    stack_a->num = stack_a->next->num;
    stack_a->next->num = temp;
    // ft_printf("sa\n");
}

void swap_b(t_list *stack_b)
{
    swap_a(stack_b);
    // ft_printf("sb\n");
}

void swap_ab(t_list *stack_a, t_list *stack_b)
{
    swap_a(stack_a);
    swap_a(stack_b);
    // ft_printf("ss\n");
}
