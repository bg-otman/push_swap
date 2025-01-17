/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:04:22 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/17 10:45:08 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/*
A non-existing file descriptor is used to call
get_next_line, forcing it to return -1 and automatically clear the static buffer.
*/
void display_error(t_list **stack_a, t_list **stack_b, char **operation)
{
    ft_putstr_fd("Error\n", 2);
    free(*operation);
    *operation = get_next_line(5);
    ft_lstclear(stack_a);
    ft_lstclear(stack_b);
    exit(1);
}

void excute_instructions(t_list **stack_a, t_list **stack_b)
{
    char *operation;
    int swp, rotate, r_rotate, push;

    operation = get_next_line(0);
    while (operation != NULL)
    {
        swp = handle_swap(operation, stack_a, stack_b);
        rotate = handle_rotate(operation, stack_a, stack_b);
        r_rotate = handle_reverse_rotate(operation, stack_a, stack_b);
        push = handle_push(operation, stack_a, stack_b);
        if (!swp && !rotate && !r_rotate && !push)
        {
            display_error(stack_a, stack_b, &operation);
        }
        free(operation);
        operation = get_next_line(0);
    }
}

void double_checker(t_list **stack_a)
{
    int i;
    int size;
    int *sorted_arr;

    i = 0;
    size = ft_lstsize(*stack_a);
    sorted_arr = sorted_version(*stack_a);
    while (i < size - 1)
    {
        if (sorted_arr[i] == sorted_arr[i + 1])
        {
            free(sorted_arr);
            ft_lstclear(stack_a);
            ft_putstr_fd("Error\n", 2);
            exit(1);
        }
        i++;
    }
    free(sorted_arr);
}

void checker_programme(t_list **stack_a, t_list **stack_b)
{
    double_checker(stack_a);
	excute_instructions(stack_a, stack_b);
	if ((ft_lstsize(*stack_b) == 0) && is_sorted(*stack_a))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

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
    checker_programme(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
    return (0);
}
