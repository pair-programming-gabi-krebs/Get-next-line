/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:01:14 by lkrebs-l          #+#    #+#             */
/*   Updated: 2021/10/08 11:01:32 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	string_len;
	size_t	i;
	char	*substr;

	if (s == NULL)
		return (NULL);
	string_len = ft_strlen(s);
	if (start > string_len)
		return (ft_strdup(""));
	if (start + len > string_len)
		len = string_len - start;
	substr = malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

size_t	ft_strlen(const char *string)
{
	size_t	i;

	i = 0;
	while (string[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dst;

	dst = malloc(ft_strlen(src) + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len1;
	int		len2;
	char	*ccat;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ccat = malloc(len1 + len2 + 1);
	if (!ccat)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		ccat[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		ccat[i + j] = s2[j];
		j++;
	}
	ccat[i + j] = '\0';
	return (ccat);
}

char	*ft_strchr(const char *s, int c)
{
	int	s_len;

	s_len = ft_strlen(s);
	while (s_len >= 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
		s_len--;
	}
	return (NULL);
}
