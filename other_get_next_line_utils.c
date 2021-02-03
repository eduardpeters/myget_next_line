/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <epeters-@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 19:38:29 by epeters-          #+#    #+#             */
/*   Updated: 2021/02/03 17:11:21 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	while (src[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	src_len;

	i = 0;
	j = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (j < (dstsize - 1) && dstsize > 0)
	{
		while (src[i] && j < (dstsize - 1))
		{
			dst[j] = src[i];
			i++;
			j++;
		}
		dst[j] = 0;
	}
	if (j > dstsize)
		j = dstsize;
	return (src_len + j - i);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	if (!s1)
		return (NULL);
	str = (char *)(malloc(sizeof(*str) * (ft_strlen(s1) + 1)));
	if (str)
	{
		i = 0;
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
		str[i] = 0;
	}
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(str = (char *)(malloc(sizeof(*str) * (len_s1 + len_s2 + 1)))))
		return (NULL);
	ft_strlcpy(str, s1, len_s1 + 1);
	ft_strlcat(str, s2, (len_s1 + len_s2 + 1));
	return (str);
}
