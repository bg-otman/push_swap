/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:20:26 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/17 09:39:34 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void clean(int *sorted_arr, t_list **stack_a)
{
	free(sorted_arr);
	ft_lstclear(stack_a);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void check_double_and_sorted(int *sorted_arr, int size, t_list **stack_a)
{
	int i;

	i = 0;
	while (i < size - 1)
	{
		if (sorted_arr[i] == sorted_arr[i + 1])
			clean(sorted_arr, stack_a);
		i++;
	}
	if (is_sorted(*stack_a))
	{
		free(sorted_arr);
		ft_lstclear(stack_a);
		exit(0);
	}
}

