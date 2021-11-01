/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:33:55 by lkrebs-l          #+#    #+#             */
/*   Updated: 2021/11/01 19:04:13 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	int		fd1;
	char	*line;
	char	*line1;
	
	fd = open("teste", O_RDONLY);
	fd1 = open("teste2", O_RDONLY);
	
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	return (0);
}
