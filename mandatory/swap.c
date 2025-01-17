/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:30:37 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/16 20:22:22 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
	if (!stack_a)
		return ;
	ft_swap(stack_a);
    ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_list *stack_b)
{
	if (!stack_b)
		return ;
	ft_swap(stack_b);
    ft_putstr_fd("sb\n", 1);
}

void	swap_ab(t_list *stack_a, t_list *stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	ft_swap(stack_a);
	ft_swap(stack_b);
    ft_putstr_fd("ss\n", 1);
}
