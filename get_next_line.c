/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslati <yslati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 14:58:44 by yslati            #+#    #+#             */
/*   Updated: 2019/12/16 18:07:57 by yslati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					fill_line(char **line, char **stc, int fd)
{
	int				len;
	char			*tmp;

	if (stc[fd])
		len = line_len(stc[fd]);
	if (stc[fd] && (len < (int)ft_strlen(stc[fd])))
	{
		tmp = ft_strjoin(*line, stc[fd], '\n');
		free(*line);
		*line = tmp;
		tmp = ft_strdup(stc[fd] + len + 1);
		free(stc[fd]);
		stc[fd] = tmp;
		return (1);
	}
	else if (stc[fd] && (len == (int)ft_strlen(stc[fd])))
	{
		tmp = ft_strjoin(*line, stc[fd], '\0');
		free(*line);
		*line = tmp;
		free(stc[fd]);
		stc[fd] = NULL;
		return (0);
	}
	return (0);
}

int					get_next_line(int fd, char **line)
{
	static char		*stc[MAX];
	char			*buff;
	char			*tmp;
	int				r;

	if (fd < 0 || fd >= MAX || BUFFER_SIZE <= 0 || !line ||
		read(fd, NULL, 0) || !(*line = ft_strdup("")))
		return (-1);
	if (!(buff = malloc(BUFFER_SIZE + 1)))
		return (-1);
	while ((r = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[r] = '\0';
		tmp = ft_strjoin(stc[fd], buff, '\0');
		free(stc[fd]);
		stc[fd] = tmp;
		if (check_static(stc[fd]) == 1)
			break ;
	}
	free(buff);
	if (r < 0)
		return (-1);
	return (fill_line(line, stc, fd));
}
