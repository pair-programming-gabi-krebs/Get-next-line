/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:50:54 by lkrebs-l          #+#    #+#             */
/*   Updated: 2021/10/07 18:26:09 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main (void)
{
	int fd;
	char *string = NULL;
	fd = open("42_no_nl", O_RDONLY);
	while (1)
	{
		string = get_next_line(fd);
		if (!string)
			break ;
		printf("%s", string);
	}
	return (0);
}
