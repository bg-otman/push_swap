/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:11:19 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/17 10:12:16 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

#include "../mandatory/push_swap.h"
#include "get_next_line/get_next_line.h"

int handle_swap(char *operation, t_list **stack_a, t_list **stack_b);
int handle_rotate(char *operation, t_list **stack_a, t_list **stack_b);
int handle_reverse_rotate(char *operation, t_list **stack_a, t_list **stack_b);
int handle_push(char *operation, t_list **stack_a, t_list **stack_b);

#endif