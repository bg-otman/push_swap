/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:14:52 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/15 12:17:47 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_slen(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char **s1, char **s2)
{
	char	*ptr;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_slen(*s1);
	s2_len = ft_slen(*s2);
	ptr = (char *)malloc((s1_len + s2_len) + 1);
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, *s1, s1_len);
	ft_memcpy(ptr + s1_len, *s2, s2_len);
	ptr[s1_len + s2_len] = '\0';
	if (*s1)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (*s2)
	{
		free(*s2);
		*s2 = NULL;
	}
	return (ptr);
}

