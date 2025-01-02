/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:30:37 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/02 09:13:36 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list *stack)
{
	int temp;
	
	if (!stack || !stack->next)
		return ;
	temp = stack->num;
	stack->num = stack->next->num;
	stack->next->num = temp;
}
void	swap_a(t_list *stack_a)
{
	ft_swap(stack_a);
	ft_printf("sa\n");
}

void	swap_b(t_list *stack_b)
{
	ft_swap(stack_b);
	ft_printf("sb\n");
}

void	swap_ab(t_list *stack_a, t_list *stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_printf("ss\n");
}
