/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:42:43 by obouizi           #+#    #+#             */
/*   Updated: 2024/12/05 20:49:14 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_puthex(unsigned int nb, char *hex)
{
	int	count;

	count = 0;
	if (nb >= 16)
		count += ft_puthex(nb / 16, hex);
	count += ft_putchar(hex[nb % 16]);
	return (count);
}