/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:10:10 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/15 21:30:56 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_overflow(char *str)
{
	long nb;

	nb = ft_atoi(str);
	if (nb > 2147483647)
		return (1);
	return (0);
}

void parse_argument(char *arr[])
{
	int i;
	int j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if ((((arr[i][j] == '-' || arr[i][j] == '+')  && !ft_isdigit(arr[i][j + 1]))
				|| ((!ft_isdigit(arr[i][j]) && !(arr[i][j] == '-' || arr[i][j] == '+')) && arr[i][j] != ' '))
				|| check_overflow(arr[i]))
			{
				ft_putstr_fd("Error\n", 2);
				free_arr(arr);
				exit(1);
			}
			j++;
		}
		i++;
	}
}
