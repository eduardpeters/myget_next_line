/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <epeters-@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 16:47:15 by epeters-          #+#    #+#             */
/*   Updated: 2021/01/28 20:36:59 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	get_next_line(int fd, char **line)
{
	int	i;
	char *buffer;
	char *prevread;

	if (!(buffer = malloc(sizeof(*buffer) * (BUFFER_SIZE + 1))))
		return (-1);
	read(fd, buffer, BUFFER_SIZE);
	buffer[BUFFER_SIZE] = '\0';
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
	{
		if (!(*line = malloc(sizeof(*line) * (i + 1))))
			return (-1);
		ft_strlcpy(*line, buffer, i + 1);
		free(buffer);
		return (1);
	}
	else
	{
		prevread = malloc(sizeof(*prevread) * (BUFFER_SIZE + 1));
		ft_strlcpy(prevread, buffer, BUFFER_SIZE + 1);
		free(buffer);
		printf("Remains: %s\n", prevread);
		free(prevread);
	}
	return (0);
}
