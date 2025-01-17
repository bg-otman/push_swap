/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_range_and_chunk.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:37:56 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/14 18:39:02 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_chunk_size(int lst_size)
{
    if (lst_size <= 10)
        return (5);
    else if (lst_size <= 50)
        return (10);
    else if (lst_size <= 100)
        return (20);
    else if (lst_size <= 500)
        return (30);
    else
        return (45);
}

int get_in_range(t_list *stack_a, int range)
{
    int first_half;
    int second_half;
    int lst_size;
    int i;
	
    lst_size = ft_lstsize(stack_a);
    first_half = -1;
    second_half = -1;
    i = 0;
    while (stack_a)
    {
        if (stack_a->num <= range)
        {
            if (i <= lst_size / 2 && first_half == -1)
                first_half = i;
            if (i > lst_size / 2)
                second_half = i;
        }
        stack_a = stack_a->next;
        i++;
    }
	if (first_half != -1 && first_half <= lst_size - second_half)
		return (first_half);
	return (second_half);
}

