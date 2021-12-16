/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:06:52 by ayassir           #+#    #+#             */
/*   Updated: 2021/12/16 12:22:35 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_join(const char *s1, const char *s2)
{
	char	*join;
	int		i;
	int		j;

	i = 0;
	j = 0;
	join = malloc((sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1)));
	if (!(join))
		return (NULL);
	while (s1[i])
	{
		join[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		join[j] = s2[i];
		j++;
		i++;
	}
	join[j] = '\0';
	free ((void *) s1);
	return (join);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	if (s1 == NULL)
		return (ft_join(ft_strdup(""), s2));
	return (ft_join(s1, s2));
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
