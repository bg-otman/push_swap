/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 10:46:15 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/15 22:30:33 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_and_swap(t_list **stack_a, t_list **stack_b)
{
	push_b(stack_b, stack_a);
	if ((*stack_b)->next && (*stack_b)->num < (*stack_b)->next->num)
		swap_b(*stack_b);
}

void push_chunks(t_list **stack_a, t_list **stack_b, int *sorted_arr)
{
	int (i), (lst_size), (chunk_size);
	i = 0;
	lst_size = ft_lstsize(*stack_a);
	chunk_size = get_chunk_size(lst_size);
    while (*stack_a)
    {
        if (i + chunk_size > lst_size)
            chunk_size = lst_size - i;
        if ((*stack_a)->num < sorted_arr[i])
		{
			push_b(stack_b, stack_a);
			if ((*stack_b)->next)
				rotate_b(stack_b);
			i++;
		}
		else if ((*stack_a)->num >= sorted_arr[i]
			&& (*stack_a)->num <= sorted_arr[i + chunk_size - 1])
		{
			push_and_swap(stack_a, stack_b);
			i++;
		}
		else
			bring_to_top(stack_a, sorted_arr[i], sorted_arr[i + chunk_size - 1]);
    }
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
	int *sorted_arr;
	
	if (ft_lstsize(*stack_a) <= 1)
			return ;
	sorted_arr = sorted_version(*stack_a);
	if (!sorted_arr)
		return ;
	lst_size = ft_lstsize(*stack_a);
	check_double_and_sorted(sorted_arr, lst_size, stack_a);
	if (lst_size == 2)
		swap_a(*stack_a);
	else if (lst_size == 3)
		sort_three(stack_a);
	else if (lst_size <= 5)
		sort_five(stack_a, stack_b);
	else
	{
		push_chunks(stack_a, stack_b, sorted_arr);
		final_sort(stack_a, stack_b);
	}
	free(sorted_arr);
}
// remove it -----
void print_lst(t_list *stack)
{
	while (stack)
	{
		ft_printf("|%d|\n", stack->num);
		stack = stack->next;
	}
}
// -----

int main(int ac, char *av[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*joined_arg;
	char	**arr;
	
	if (ac < 2)
		return (0);
	handle_empty_str(av);
	joined_arg = process_input(av);	
	if (!joined_arg)
		return (1);
	arr = ft_split(joined_arg, ' ');
	free(joined_arg);
	if (!arr)
		return (1);
	parse_argument(arr);
	stack_b = NULL;
	stack_a = create_lst(arr);
	free_arr(arr);
	if (!stack_a)
		return (1);
	sort(&stack_a, &stack_b);	
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}
