/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:19:35 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/17 10:08:16 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int handle_swap(char *operation, t_list **stack_a, t_list **stack_b)
{
    if (!ft_strcmp(operation, "sa\n"))
    {
        ft_swap(*stack_a);
        return (1);
    }
    else if (!ft_strcmp(operation, "sb\n"))
    {
        ft_swap(*stack_b);
        return (1);
    }
    else if (!ft_strcmp(operation, "ss\n"))
    {
        ft_swap(*stack_a);
        ft_swap(*stack_b);
        return (1);
    }
    return (0);
}
