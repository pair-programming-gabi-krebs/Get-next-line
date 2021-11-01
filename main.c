/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:33:55 by lkrebs-l          #+#    #+#             */
/*   Updated: 2021/11/01 18:47:56 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;

	line = malloc(1 * sizeof(char));
	fd = open("teste", O_RDONLY);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		printf("%s", line);
	}
	return (0);
}
