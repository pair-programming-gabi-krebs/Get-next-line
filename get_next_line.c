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


char	*format_line(char **buffer, char *swap, int i)
{
	char	*line_formated;

	*buffer = ft_substr(swap, i + 1, ft_strlen(swap));
	swap[i + 1] = '\0';
	line_formated = swap;
	return (line_formated);
}

char	*get_line(int fd, char **buffer, char  *read_buffer)
{
	int		read_bytes;
	char	*swap;
	char	*find_new_line;
	int		new_line_position;

	find_new_line = ft_strchr(*buffer, '\n');
	while (find_new_line == NULL)
	{
		read_bytes = read(fd, read_buffer, BUFFER_SIZE);
		if (read_bytes <= 0) //verificar retorno read_bytes == 0
			return (NULL);
		swap = ft_strjoin(*buffer, read_buffer);
		*buffer = swap;
		find_new_line = ft_strchr(*buffer, '\n');
	}
	new_line_position = 0;
	while (swap[new_line_position] != '\n')
		new_line_position++;
	return (format_line(buffer, swap, new_line_position));
// função do format line é enviar o aaaaa/nbb e guardar o bb dentro do buffer
}


char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD];
	char		*read_buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE == 0) //mais um ||
		return (NULL);
	if (!buffer[fd])
			buffer[fd] = ft_strdup("");
	read_buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!read_buffer)
		return (NULL);
	line = get_line(fd, &buffer[fd], read_buffer);
	return (line);
}
