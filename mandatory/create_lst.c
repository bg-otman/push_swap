/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:31:01 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/16 15:11:33 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *create_lst(char *arr[])
{
	t_list *lst;
	t_list *new_node;
	int i;
	
	i = 0;
	if (!arr[i])
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	lst = ft_lstnew(ft_atoi(arr[i++]));
	if (!lst)
		return (NULL);
	new_node = lst;
	while (arr[i])
	{
		new_node->next = ft_lstnew(ft_atoi(arr[i++]));
		if (!new_node->next)
		{
			ft_lstclear(&lst);
			return (NULL);
		}
		new_node = new_node->next;
	}
	return (lst);
}
