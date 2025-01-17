/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:11:07 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/17 10:15:25 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int handle_reverse_rotate(char *operation, t_list **stack_a, t_list **stack_b)
{
    if (!ft_strcmp(operation, "rra\n"))
    {
        reverse_rotate(stack_a);
        return (1);
    }
    else if (!ft_strcmp(operation, "rrb\n"))
    {
        reverse_rotate(stack_b);
        return (1);
    }
    else if (!ft_strcmp(operation, "rrr\n"))
    {
        reverse_rotate(stack_a);
        reverse_rotate(stack_b);
        return (1);
    }
    return (0);
}
