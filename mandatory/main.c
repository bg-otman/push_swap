/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:34:48 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/17 10:28:27 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
