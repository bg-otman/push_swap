/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_version.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:18:51 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/16 15:56:29 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_swp(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void sort_arr(int *arr, int size)
{
    int i;
    int j;

    i = 0;
    while (i < size)
    {
        j = i + 1;
        while (j < size)
        {
            if (arr[i] > arr[j])
                ft_swp(&arr[i], &arr[j]);
            j++;
        }
        i++;
    }
    
}

int *sorted_version(t_list *stack_a)
{
    int *arr;
    int lst_size;
    int i;

    if (!stack_a)
        return (NULL);
    lst_size = ft_lstsize(stack_a);
    arr = malloc(sizeof(int) * lst_size);
    if (!arr)
        return (NULL);
    i = 0;
    while (stack_a)
    {
        arr[i++] = stack_a->num;
        stack_a = stack_a->next;
    }
    sort_arr(arr, lst_size);
    return (arr);
}

