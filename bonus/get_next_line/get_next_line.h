/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:01:23 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/17 10:22:41 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

char	*get_next_line(int fd);
char	*get_last_line(char **buffer, ssize_t bytes_read);
char	*allocate_line(char *buffer);
int		check_newline(char *buffer);
ssize_t	read_data(int fd, char **buffer);
char	*allocate_and_free(char **buffer);

#endif
