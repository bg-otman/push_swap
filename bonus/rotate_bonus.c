/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:08:40 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/17 10:15:10 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int handle_rotate(char *operation, t_list **stack_a, t_list **stack_b)
{
    if (!ft_strcmp(operation, "ra\n"))
    {
        ft_rotate(stack_a);
        return (1);
    }
    else if (!ft_strcmp(operation, "rb\n"))
    {
        ft_rotate(stack_b);
        return (1);
    }
    else if (!ft_strcmp(operation, "rr\n"))
    {
        ft_rotate(stack_a);
        ft_rotate(stack_b);
        return (1);
    }
    return (0);
}
