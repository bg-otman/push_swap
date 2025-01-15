/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:07:36 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/15 21:07:49 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_len(char *av[])
{
	int i;
	int len;

	i = 1;
	len = 0;
	while (av[i])
	{
		len += ft_strlen(av[i]);
		if (av[i + 1])
			len++;
		i++;
	}
	return (len);
}

char	*process_input(char *av[])
{
	int		total_length;
	int		i;
	char	*result;
	int		offset;
	int		len;
	
	total_length = get_len(av);
	result = malloc(total_length + 1);
	if (!result)
		return (NULL);
	i = 1;
	offset = 0;
	while (av[i])
	{
		len = ft_strlen(av[i]);
		ft_memcpy(result + offset, av[i], len);
		offset += len;
		if (av[i + 1])
			result[offset++] = ' ';
		i++;
	}
	result[offset] = '\0';
	return (result);
}
