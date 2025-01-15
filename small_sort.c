/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:33:48 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/15 22:27:34 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_min_element(t_list *stack)
{
	int min;
	
	min = stack->num;
	stack = stack->next;
	while (stack)
	{
		if ((stack->num) < min)
			min = stack->num;
		stack = stack->next;
	}
	return (min);
}

void sort_three(t_list **stack)
{
	while(!is_sorted(*stack))
	{
		if (((*stack)->num > (*stack)->next->num) && ((*stack)->num > (*stack)->next->next->num))
			rotate_a(stack);
		else if ((*stack)->num > (*stack)->next->num)
			swap_a(*stack);
		else if (((*stack)->num < (*stack)->next->num) && ((*stack)->next->num > (*stack)->next->next->num))
			reverse_rotate_a(stack);
	}
}

void sort_five(t_list **stack_a, t_list **stack_b)
{
	int min;
	int index;
	
	while (ft_lstsize(*stack_a) > 3)
	{
		min = get_min_element(*stack_a);
		index = get_index(*stack_a, min);
		if (index <= ft_lstsize(*stack_a) / 2)
            while ((*stack_a)->num != min)
                rotate_a(stack_a);
        else
            while ((*stack_a)->num != min)
                reverse_rotate_a(stack_a);
        push_b(stack_b, stack_a);
	}
	sort_three(stack_a);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

