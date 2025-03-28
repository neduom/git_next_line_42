/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moud <mel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:43:06 by mel-moud          #+#    #+#             */
/*   Updated: 2024/12/20 14:32:06 by mel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_readed_line(char *start)
{
	int		i;
	char	*line;

	if (!start || !start[0])
		return (NULL);
	i = 0;
	while (start[i] && start[i] != '\n')
		i++;
	if (start[i] == '\n')
		i++;
	line = (char *)malloc(1 + i);
	if (!line)
		return (NULL);
	i = 0;
	while (start[i] && start[i] != '\n')
	{
		line[i] = start[i];
		i++;
	}
	if (start[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static int	find_new_start(char *start)
{
	int	i;

	i = 0;
	while (start[i] && start[i] != '\n')
		i++;
	if (start[i] == '\n')
		i++;
	return (i);
}

static char	*ft_move_start(char *start)
{
	char	*new_buff;
	int		i;
	int		j;

	if (!start)
		return (NULL);
	i = find_new_start(start);
	if (start[i] == '\0')
	{
		free(start);
		return (NULL);
	}
	new_buff = malloc(1 + ft_strlen(start) - i);
	if (!new_buff)
		return (NULL);
	j = 0;
	while (start[i + j])
	{
		new_buff[j] = start[i + j];
		j++;
	}
	new_buff[j] = '\0';
	free(start);
	return (new_buff);
}

char	*get_next_line(int fd)
{
	char		*tmp;
	int			fd_read;
	static char	*start_str[1024] = {NULL};

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	fd_read = 1;
	tmp = malloc(1 + (size_t)BUFFER_SIZE);
	if (!tmp)
		return (NULL);
	while (!ft_strchr(start_str[fd], '\n') && fd_read != 0)
	{
		fd_read = read(fd, tmp, BUFFER_SIZE);
		if (fd_read == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[fd_read] = '\0';
		start_str[fd] = ft_strjoin(start_str[fd], tmp);
	}
	free(tmp);
	tmp = ft_readed_line(start_str[fd]);
	start_str[fd] = ft_move_start(start_str[fd]);
	return (tmp);
}
