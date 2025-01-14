/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:33:48 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/14 11:37:34 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
