/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <epeters-@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 16:47:15 by epeters-          #+#    #+#             */
/*   Updated: 2021/02/03 17:27:03 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	char	*ptr_s;

	ptr_s = (char *)(s);
	if (c == 0)
		return (ptr_s + ft_strlen(s));
	while (*ptr_s)
	{
		if (*ptr_s == c)
			return (ptr_s);
		ptr_s++;
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!(str = (char *)(malloc(sizeof(*str) * (len + 1)))))
		return (NULL);
	j = 0;
	if (start < ft_strlen(s))
	{
		i = start;
		while (s[i] && j < len)
		{
			str[j] = s[i];
			i++;
			j++;
		}
	}
	while (j < (len + 1))
	{
		str[j] = '\0';
		j++;
	}
	return (str);
}

int		ft_next_line(char **prev, char **line)
{
	int		len;
	char	*temp;

	len = 0;
	while ((*prev)[len] != '\n' && (*prev)[len] != '\0')
		len++;
	if ((*prev)[len] == '\n')
	{
		*line = ft_substr(*prev, 0, len);
		temp = ft_strdup(&(*prev)[len + 1]);
		free(*prev);
		*prev = temp;
		return (1);
	}
	else
	{
		*line = ft_strdup(*prev);
		free(*prev);
		return (0);
	}
}

int		ft_return(int fd, char **prev, char **line, int nreturn)
{
	if (nreturn < 0)
		return (-1);
	else if (nreturn == 0 && prev[fd] == NULL)
		return (0);
	else
		return (ft_next_line(&prev[fd], line));
}

int		get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*prev[FD_SIZE];
	char		*temp;
	int			nreturn;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((nreturn = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[nreturn] = '\0';
		if (prev[fd] == NULL)
			prev[fd] = ft_strdup(buffer);
		else
		{
			temp = ft_strjoin(prev[fd], buffer);
			free(prev[fd]);
			prev[fd] = temp;
		}
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (ft_return(fd, prev, line, nreturn));
}
