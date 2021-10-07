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
#include <stdio.h>

void ft_free(char **ptr)
{
		free(*ptr);
		ptr = NULL;
}

char	*format_line(char **buffer, char *swap, int new_line_index)
{
	char	*line_formated;

	if (**buffer == 0 && !swap && new_line_index < 0)
	{
		ft_free(buffer);
		return (NULL);
	}
	if (new_line_index < 0)
	{
		line_formated = ft_strdup(*buffer);
		ft_free(buffer);
		return (line_formated);
	}
	*buffer = ft_substr(swap, new_line_index + 1, ft_strlen(swap));
	swap[new_line_index + 1] = '\0';
	line_formated = swap;
	swap = NULL;
	return (line_formated);
}

char	*get_line(int fd, char **buffer, char  *read_buffer)
{
	int		read_bytes;
	char	*swap;
	char	*find_new_line;
	int		new_line_position;

	swap = NULL;
	find_new_line = ft_strchr(*buffer, '\n');
	while (find_new_line == NULL)
	{
		read_bytes = read(fd, read_buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
		{
			new_line_position = -1;
			return (format_line(buffer,swap, new_line_position));
		}
		read_buffer[read_bytes] = '\0';
		swap = ft_strjoin(*buffer, read_buffer);
		ft_free(buffer);
		*buffer = swap;
		find_new_line = ft_strchr(*buffer, '\n');
	}
	if (*buffer)
		swap = *buffer;
	new_line_position = 0;
	while (swap[new_line_position] != '\n') // nl = ft_strlen(swap)?
		new_line_position++;
	return (format_line(buffer, swap, new_line_position));
}


char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD];
	char		*read_buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD)
		return (NULL);
	if (!buffer[fd])
			buffer[fd] = ft_strdup("");
	read_buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!read_buffer)
		return (NULL);
	line = get_line(fd, &buffer[fd], read_buffer);
	ft_free(&read_buffer); // começou a passar em alguns testes.
	return (line);
}
