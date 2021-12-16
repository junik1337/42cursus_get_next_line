/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:44:47 by ayassir           #+#    #+#             */
/*   Updated: 2021/12/16 11:54:47 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*func_rest(char *save, int len, int i)
{
	int			j;
	char		*ptr;

	ptr = malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (NULL);
	j = 0;
	while (j < len)
	{
		ptr[j] = save[i];
		j++;
		i++;
	}
	ptr[j] = '\0';
	if (ptr[0] == '\0')
	{
		free(ptr);
		free(save);
		return (NULL);
	}
	free(save);
	return (ptr);
}

static char	*get_rest(char *save)
{
	int			i;
	int			len;

	i = 0;
	len = (int) ft_strlen(save);
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\0')
	{
		free(save);
		return (NULL);
	}
	else
		i++;
	len = len - i + 1;
	return (func_rest(save, len, i));
}

static char	*get_line(char *save)
{
	int		i;
	char	*ptr;
	int		j;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	ptr = malloc(sizeof(char) * (i + 1));
	if (!ptr)
		return (NULL);
	j = 0;
	while (j < i)
	{
		ptr[j] = save[j];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}

static char	*get_next(char *save, int fd)
{
	int				rd;
	char			*buf;

	rd = 1;
	while (rd > 0)
	{
		buf = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd < 0)
		{
			free (buf);
			return (NULL);
		}
		if (rd == 0)
		{
			free(buf);
			break ;
		}
		buf[rd] = '\0';
		save = ft_strjoin(save, buf);
		free(buf);
		if (ft_strchr(save) != NULL)
			break ;
	}
	return (save);
}

char	*get_next_line(int fd)
{
	static char		*save[10240];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save[fd] = get_next(save[fd], fd);
	if (save[fd] == NULL)
		return (NULL);
	line = get_line(save[fd]);
	save[fd] = get_rest(save[fd]);
	return (line);
}
