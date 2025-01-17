/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bring_to_top.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 22:05:14 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/15 22:06:04 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void bring_to_top(t_list **stack_a, int first, int last)
{
	int i;
	int lst_size;
	t_list *temp;

	i = 0;
	lst_size = ft_lstsize(*stack_a);
	temp = *stack_a;
	while (temp && !(temp->num >= first && temp->num <= last))
	{
		temp = temp->next;
		i++;
	}
	if (i > lst_size / 2)
		reverse_rotate_a(stack_a);
	else
		rotate_a(stack_a);
}
