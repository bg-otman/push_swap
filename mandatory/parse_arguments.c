/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:10:10 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/16 15:54:08 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_overflow(char *str)
{
	int i;
	int sign;
	long long result;
	
	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		result = result * 10 + (str[i] - '0');
		if (result > 2147483647 ||  result < -2147483648)
			return (1);
		i++;
	}
	if (i == 0 || (i == 1 && (str[0] == '-' || str[0] == '+')))
		return (1);
	return (0);
}

void parse_argument(char *arr[])
{
	int i = 0;

	while (arr[i])
	{
		if (check_overflow(arr[i]))
		{
			ft_putstr_fd("Error\n", 2);
			free_arr(arr);
			exit(1);
		}
		i++;
	}
}
