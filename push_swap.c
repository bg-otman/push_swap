/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 10:46:15 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/09 21:30:14 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *create_lst(char *av[])
{
	t_list *lst;
	t_list *new_node;
	int i;
	
	i = 1;
	lst = ft_lstnew(ft_atoi(av[i++]));
	if (!lst)
		return (NULL);
	new_node = lst;
	while (av[i])
	{
		new_node->next = ft_lstnew(ft_atoi(av[i]));
		if (!new_node->next)
		{
			ft_lstclear(&lst);
			return (NULL);
		}
		new_node = new_node->next;
		i++;
	}
	return (lst);
}

void print_lst(t_list *stack)
{
	while (stack)
	{
		ft_printf("|%d|\n", stack->num);
		stack = stack->next;
	}
}
// void split_list(t_list **stack_a, t_list **stack_b)
// {
// 	int lst_size;
// 	int i;
	
// 	i = 0;
// 	lst_size = ft_lstsize(*stack_a) / 2;
// 	while (i < lst_size)
// 	{
// 		push_b(stack_b, stack_a);
// 		i++;
// 	}
// }

int get_min_element(t_list *stack)
{
	int min;
	t_list *temp;

	min = stack->num;
	temp = stack->next;
	while (temp)
	{
		if ((temp->num) < min)
			min = temp->num;
		temp = temp->next;
	}
	return (min);
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

int is_sorted_rev(t_list *stack)
{
	t_list *temp;

	temp = stack;
	while (temp && temp->next)
	{
		if (temp->num < temp->next->num)
			return (0);
		temp = temp->next;
	}
	return (1);
}
// void insert(t_list **stack_a, t_list **stack_b)
// {
//     int i, j, lst_size;

//     if (!(*stack_b) || (*stack_a)->num > (*stack_b)->num)
// 	{
// 		push_b(stack_b, stack_a);
// 		return ;
// 	}
// 	lst_size = ft_lstsize(*stack_b);
// 	i = get_right_position((*stack_a)->num, *stack_b);
// 	j = 0;
// 	if (i > lst_size / 2)
// 	{
// 		while (lst_size - i > 0)
// 		{
// 			reverse_rotate_b(stack_b);
// 			j++;
// 			i++;
// 		}
// 		push_b(stack_b, stack_a);
// 		while (j--)
// 			rotate_b(stack_b);
// 	}
// 	else
// 	{
// 		while (i--)
// 		{
// 			rotate_b(stack_b);
// 			j++;
// 		}
// 		push_b(stack_b, stack_a);
// 		while (j--)
// 			reverse_rotate_b(stack_b);
// 	}
// }

int get_right_position(int num, t_list *stack)
{
	t_list *temp;
	int i;

	temp = stack;
	i = 0;
	
	while (temp && temp->next)
	{
		if (temp->num < num && temp->next->num > num)
			return (i + 1);
		temp = temp->next;
		i++;
	}
	return (i);
}

int is_sorted(t_list *stack)
{
	t_list *temp;

	temp = stack;
	while (temp && temp->next)
	{
		if (temp->num > temp->next->num)
			return (0);
		temp = temp->next;
	}
	return (1);
}

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
	if (first_half == -1 && second_half == -1)
		return (-1);
	else if (first_half != -1 && first_half <= lst_size - second_half)
		return (first_half);
	return (second_half);
}

int get_chunk_size(int dataset_size)
{
    if (dataset_size <= 10)
        return dataset_size;
    else if (dataset_size <= 50)
        return dataset_size / 5;
    else if (dataset_size <= 100)
        return dataset_size / 10;
    else
        return dataset_size / 15;
}

void rr_or_rotate_a(t_list **stack_a, t_list **stack_b)
{
	if (((*stack_b) && (*stack_b)->next) && (*stack_b)->num < (*stack_b)->next->num)
		rotate_ab(stack_a, stack_b);
	else
		rotate_a(stack_a);
}

void rrr_or_reverse_a(t_list **stack_a, t_list **stack_b)
{
	t_list *last;

	last = ft_lstlast(*stack_b);
	if ((*stack_b) && last->num > (*stack_b)->num)
		reverse_rotate_ab(stack_a, stack_b);
	else
		reverse_rotate_a(stack_a);
}

void push_chunks(t_list **stack_a, t_list **stack_b)
{
    int range;
	int index;
    int lst_size;
	int chunk_size;

    lst_size = ft_lstsize(*stack_a);
	chunk_size = get_chunk_size(lst_size);
    range = get_min_element(*stack_a) + chunk_size;
    while (lst_size)
    {
        index = get_in_range(*stack_a, range);
        if (index < 0)
        {
            range += chunk_size;
			continue ;
        }
        if (index > lst_size / 2)
            while (index++ < lst_size)
                rrr_or_reverse_a(stack_a, stack_b);
        else
			while (index-- > 0)
				rr_or_rotate_a(stack_a, stack_b);
		push_b(stack_b, stack_a);
		lst_size--;
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
