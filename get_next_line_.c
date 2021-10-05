/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:52:20 by gcosta-d          #+#    #+#             */
/*   Updated: 2021/10/05 13:52:222 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD];
	int			*read_bytes;
	int			*swap;
	char		*read_buffer;

	if (fd < 0 || BUFFER_SIZE == 0) //mais um ||
		return (NULL);
	read_buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!read_buffer)
		return (NULL);
	read_bytes = read(fd, read_buffer, BUFFER_SIZE);
	if (read_bytes <= 0) //verificar retorno read_bytes == 0
		return (NULL);
}

