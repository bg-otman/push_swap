/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 10:46:15 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/14 11:48:28 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void bring_to_top(t_list **stack, int index)
{
    int size = ft_lstsize(*stack);

    if (index <= size / 2)
    {
        while (index-- > 0)
            rotate_a(stack);
    }
    else
    {
        index = size - index;
        while (index-- > 0)
            reverse_rotate_a(stack);
    }
}

void push_chunks(t_list **stack_a, t_list **stack_b)
{
	int *sorted_arr;
	int i;
	int lst_size;
	int chunk_size;

	sorted_arr = sorted_version(*stack_a);
	i = 0;
	lst_size = ft_lstsize(*stack_a);
	chunk_size = get_chunk_size(lst_size);
    while (*stack_a)
    {
        if (i + chunk_size > lst_size)
            chunk_size = lst_size - i;
        if ((*stack_a)->num <= sorted_arr[i])
		{
			push_and_sort_b(stack_a, stack_b);
			rotate_b(stack_b);
		}
		else if ((*stack_a)->num > sorted_arr[i] && (*stack_a)->num <= sorted_arr[i + chunk_size - 1])
		{
			push_and_sort_b(stack_a, stack_b);
			i++;
		}
		else
			bring_to_top(stack_a, get_in_range(*stack_a, sorted_arr[i + chunk_size - 1]));
    }
	free(sorted_arr);
}

void final_sort(t_list **stack_a, t_list **stack_b)
{
	int max;
	int lst_size;
	int index;
	
	while (*stack_b)
	{
		max = get_max_element(*stack_b);
		lst_size = ft_lstsize(*stack_b);
		index = get_index(*stack_b, max);

		if (index > lst_size / 2)
		{
			while (index++ < lst_size)
				reverse_rotate_b(stack_b);
		}
		else
		{
			while (index--)
				rotate_b(stack_b);
		}
		push_a(stack_a, stack_b);
	}
}

void sort(t_list **stack_a, t_list **stack_b)
{
	int lst_size;

	if (is_sorted(*stack_a))
			return ;
	lst_size = ft_lstsize(*stack_a);
	if (lst_size == 2)
		swap_a(*stack_a);
	else if (lst_size == 3)
		sort_three(stack_a);
	else
	{
		push_chunks(stack_a, stack_b);
		final_sort(stack_a, stack_b);
	}
}

void print_lst(t_list *stack)
{
	while (stack)
	{
		ft_printf("|%d|\n", stack->num);
		stack = stack->next;
	}
}

int main(int ac, char *av[])
{
	t_list *stack_a;
	t_list *stack_b;
	
	if (ac <= 2)
		exit(0);
	stack_b = NULL;
	stack_a = create_lst(av);
	sort(&stack_a, &stack_b);
	// ft_printf("------stack_a------\n");
	// print_lst(stack_a);
	// ft_printf("------stack_b------\n");
	// print_lst(stack_b);
	return (0);
}
