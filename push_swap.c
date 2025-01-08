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

void sort_three(t_list **stack_a)
{
    int first, second, third;

    if (!(*stack_a) || !(*stack_a)->next || !(*stack_a)->next->next)
        return;

    first = (*stack_a)->num;
    second = (*stack_a)->next->num;
    third = (*stack_a)->next->next->num;

    if (first > second && first > third)
        rotate_a(stack_a);
    if ((*stack_a)->num > (*stack_a)->next->num)
        swap_a(*stack_a);
    if ((*stack_a)->next->num > (*stack_a)->next->next->num)
    {
        reverse_rotate_a(stack_a);
        if ((*stack_a)->num > (*stack_a)->next->num)
            swap_a(*stack_a);
    }
}

int get_in_range(t_list *stack_a, int range)
{
    t_list *temp;
    int i;

    temp = stack_a;
    i = 0;
    while (temp)
    {
        if (temp->num <= range)
            return (i);
        temp = temp->next;
        i++;
    }
    return (-1);
}


int get_right_position(int num, t_list *stack)
{
    t_list *temp;
    int i;

    temp = stack;
    i = 0;

    while (temp && temp->next)
    {
        if (temp->num > num && temp->next->num < num)
            return (i + 1);
        temp = temp->next;
        i++;
    }
    return (i);
}


void insert(t_list **stack_a, t_list **stack_b)
{
    int i, j, lst_size;

    if (*stack_b)
    {
        lst_size = ft_lstsize(*stack_b);

        if ((*stack_a)->num > (*stack_b)->num)
        {
            push_b(stack_b, stack_a);
        }
        else
        {
            i = get_right_position((*stack_a)->num, *stack_b);
            j = 0;

            if (i > lst_size / 2)
            {
                while (lst_size - i > 0)
                {
                    reverse_rotate_b(stack_b);
                    j++;
                    i++;
                }
				// push_b(stack_b, stack_a);
				// while (j--)
				//     rotate_b(stack_b);
            }
            else
            {
                while (i--)
                {
                    rotate_b(stack_b);
                    j++;
                }
				// push_b(stack_b, stack_a);
				// while (j--)
				//     reverse_rotate_b(stack_b);
            }

            push_b(stack_b, stack_a);
            while (j--)
                reverse_rotate_b(stack_b);
        }
    }
    else
    {
        push_b(stack_b, stack_a);
    }
}

void push_chunks(t_list **stack_a, t_list **stack_b)
{
    int min, max, range, index;
    int lst_size;

    lst_size = ft_lstsize(*stack_a);
    min = get_min_element(*stack_a);
    max = get_max_element(*stack_a);
    range = (max - min) / 5;

    while (lst_size > 3)
    {
        index = get_in_range(*stack_a, range);
        if (index < 0)
        {
            range += (max - min) / 5;
            if (range > max)
                range = max;
            index = get_in_range(*stack_a, range);
        }
        if (index > lst_size / 2)
        {
            while (index++ < lst_size)
                reverse_rotate_a(stack_a);
        }
        else
        {
            while (index-- > 0)
                rotate_a(stack_a);
        }
        insert(stack_a, stack_b);
        lst_size--;
        if (is_sorted(*stack_a))
            break;
    }
    if (lst_size == 3)
        sort_three(stack_a);
}

void sort(t_list **stack_a, t_list **stack_b)
{
    if (is_sorted(*stack_a))
        return;
    push_chunks(stack_a, stack_b);
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