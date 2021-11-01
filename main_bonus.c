/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 19:05:54 by lkrebs-l          #+#    #+#             */
/*   Updated: 2021/11/01 19:07:32 by lkrebs-l         ###   ########.fr       */
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
	
	line = get_next_line(fd);
	line1 = get_next_line(fd1);
	printf("%s", line);
	printf("%s", line1);

	line = get_next_line(fd);
	line1 = get_next_line(fd1);
	printf("%s", line);
	printf("%s", line1);
	return (0);
}
