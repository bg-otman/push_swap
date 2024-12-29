/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 10:46:15 by obouizi           #+#    #+#             */
/*   Updated: 2024/12/29 14:27:26 by obouizi          ###   ########.fr       */
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

int main(int ac, char *av[])
{
	t_list *stack_a;
	t_list *stack_b;
	
	if (ac <= 2)
		exit(0);
	stack_a = create_lst(av);
	stack_b = create_lst(av);
	// swap_a(stack_a);
	// swap_b(stack_b);
	// swap_ab(stack_a, stack_b);
	ft_printf("------stack_a------\n");
	while (stack_a)
	{
		ft_printf("|%d|\n", stack_a->num);
		stack_a = stack_a->next;
	}
	ft_printf("------stack_b------\n");
	while (stack_b)
	{
		ft_printf("|%d|\n", stack_b->num);
		stack_b = stack_b->next;
	}
	return (0);
}

// 2 1 3 6 5 8