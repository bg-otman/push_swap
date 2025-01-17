/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:11:51 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/17 10:15:35 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int handle_push(char *operation, t_list **stack_a, t_list **stack_b)
{
    if (!ft_strcmp(operation, "pa\n"))
    {
        ft_push(stack_a, stack_b);
        return (1);
    }
    else if (!ft_strcmp(operation, "pb\n"))
    {
        ft_push(stack_b, stack_a);
        return (1);
    }
    else
        return (0);
}
