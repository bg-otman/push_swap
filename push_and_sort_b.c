/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_sort_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:37:02 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/14 11:37:17 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_and_sort_b(t_list **stack_a, t_list **stack_b)
{	
	if (!(*stack_b))
	{
		push_b(stack_b, stack_a);
		return ;
	}
	if ((*stack_b)->next && (*stack_b)->num < (*stack_b)->next->num)
		ss_or_swap_b(*stack_a, *stack_b);
	push_b(stack_b, stack_a);
}
