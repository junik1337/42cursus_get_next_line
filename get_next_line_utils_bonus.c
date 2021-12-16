/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:45:40 by ayassir           #+#    #+#             */
/*   Updated: 2021/12/16 11:35:41 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*p;
	int		i;

	i = 0;
	p = malloc(ft_strlen(s1) + 1);
	if (!p)
		return (0);
	while (s1[i] != '\0')
	{
		*(p + i) = *(s1 + i);
		i++;
	}
	*(p + i) = '\0';
	return (p);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	int		j;

	i = 0;
	j = (int) ft_strlen(src);
	if (size > 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (j);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	str_len;
	char	*str;

	if (!s1)
		s1 = ft_strdup("");
	str_len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc((str_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str + ft_strlcpy(str, s1, str_len + 1), s2, str_len + 1);
	free ((void *) s1);
	return (str);
}

char	*ft_strchr(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return ((char *)(str + i));
	else
		return (0);
}
