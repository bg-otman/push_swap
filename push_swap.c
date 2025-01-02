/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 10:46:15 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/02 11:51:59 by obouizi          ###   ########.fr       */
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
int get_min_element(t_list **stack)
{
	int min;
	t_list *temp;

	min = (*stack)->num;
	temp = (*stack)->next;
	while (temp)
	{
		if ((temp->num) < min)
			min = temp->num;
		temp = temp->next;
	}
	return (min);
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

void sort(t_list **stack_a, t_list **stack_b)
{
	int min;
	t_list *temp;
	t_list *new_head;

	if (is_sorted(*stack_a))
			return ;
	temp = (*stack_a);
	while (temp->next)
	{
		min = get_min_element(stack_a);
		new_head = temp->next;
		if (temp->num == min)
		{
			push_b(stack_b, stack_a);
			temp = new_head;
		}
		else if (temp->next && ((temp->next->num) == min))
		{
			swap_a(*stack_a);
			if (is_sorted(*stack_a))
				break ;
			push_b(stack_b, stack_a);
			temp = new_head;
		}
		else
		{
			reverse_rotate_a(stack_a);
			temp = (*stack_a);
		}
		if (is_sorted(*stack_a))
			break ;
	}
	while (*stack_b)
		push_a(stack_a, stack_b);
	
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
	ft_printf("------stack_a------\n");
	print_lst(stack_a);
	ft_printf("------stack_b------\n");
	print_lst(stack_b);
	return (0);
}