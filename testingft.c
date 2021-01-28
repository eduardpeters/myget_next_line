/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testingft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <epeters-@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:47:15 by epeters-          #+#    #+#             */
/*   Updated: 2021/01/28 20:36:57 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	path[] = "muchaslineas";
	//char	c;
	char	*filestr;
	char	*filestr2;
	char	**lines;

	if ((fd = open(path, O_RDONLY)) == -1)
		return (-1);
	filestr = malloc(sizeof(*filestr) * (BUFFER_SIZE + 1));
	read(fd, filestr, BUFFER_SIZE);
	filestr[BUFFER_SIZE] = '\0';
	printf("%d\n", fd);
	filestr2 = malloc(sizeof(*filestr2) * (BUFFER_SIZE + 1));
	read(fd, filestr2, BUFFER_SIZE);
	filestr2[BUFFER_SIZE] = '\0';
	close(fd);
	printf("%s\n", filestr);
	printf("%s\n", filestr2);
	free(filestr);
	free(filestr2);
	printf("get_next_line...\n");
	if ((fd = open(path, O_RDONLY)) == -1)
		return (-1);
	lines = malloc(sizeof(*lines) * 5);
	int i = 0;
	while (i < 5)
		lines[i++] = 0;
	printf("Result: %d\n", get_next_line(fd, lines));
	printf("%s\n", lines[0]);
	i = 0;
	while (i < 5)
		free(lines[i++]);
	free(lines);
	return (0);
}