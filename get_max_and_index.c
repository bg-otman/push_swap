/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max_and_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:40:07 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/14 11:41:15 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_index(t_list *stack, int num)
{
	t_list *temp;
	int index;

	temp = stack;
	index = 0;
	while (temp)
	{
		if (num == (temp->num))
			return (index);
		temp = temp->next;
		index++;
	}
	return (index);
}

int get_max_element(t_list *stack)
{
	int max;
	t_list *temp;

	max = stack->num;
	temp = stack->next;
	while (temp)
	{
		if ((temp->num) > max)
			max = temp->num;
		temp = temp->next;
	}
	return (max);
}
