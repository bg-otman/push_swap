/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_empty_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:05:37 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/15 21:06:06 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_all_space(char *str)
{
    int i;
    i = 0;
    while (str[i])
    {
        if (str[i] != ' ')
            return (0);
        i++;
    }
    return (1);
}

int    handle_empty_str(char **str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (is_all_space(str[i]))
        {
			ft_putstr_fd("Error\n", 2);
			exit(1);
        }
        i++;
    }
    return (0);
}
