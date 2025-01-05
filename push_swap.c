/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 10:46:15 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/04 15:03:17 by obouizi          ###   ########.fr       */
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
int get_max_element(t_list **stack)
{
	int max;
	t_list *temp;

	max = (*stack)->num;
	temp = (*stack)->next;
	while (temp)
	{
		if ((temp->num) > max)
			max = temp->num;
		temp = temp->next;
	}
	return (max);
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


void sort_ascending(t_list **stack_a, t_list **stack_b)
{
	int min;
	int min_index;
	t_list *temp;
	int lst_size;
	
	temp = (*stack_a);
	lst_size = ft_lstsize(*stack_a);
	while (temp->next)
	{
		min = get_min_element(temp);
		min_index = get_index(temp, min);
		if (temp->num == min)
		{
			push_b(stack_b, stack_a);
			lst_size--;
		}
		else if (temp->next && ((temp->next->num) == min))
			swap_a(*stack_a);
		else if (lst_size - min_index < min_index)
			reverse_rotate_a(stack_a);
		else
			rotate_a(stack_a);
			
		if (is_sorted(*stack_a))
			break ;
		temp = (*stack_a);
	}
}

// void sort_descending(t_list **stack_b)
// {
// }

void sort(t_list **stack_a, t_list **stack_b)
{
	if (is_sorted(*stack_a))
			return ;
	// split_list(stack_a, stack_b);
	sort_ascending(stack_a, stack_b);
	while (*stack_b)
		push_a(stack_a, stack_b);
	
}


int main(int ac, char *av[])
{
	t_list *stack_a;
	t_list *stack_b;
	
	if (ac <= 3)
		exit(0);
	stack_b = NULL;
	stack_a = create_lst(av);
	sort(&stack_a, &stack_b);
	ft_printf("------stack_a------\n");
	print_lst(stack_a);
	ft_printf("------stack_b------\n");
	print_lst(stack_b);
	return (0);
}