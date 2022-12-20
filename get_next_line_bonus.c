/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:20:33 by maaliber          #+#    #+#             */
/*   Updated: 2022/12/07 11:54:40 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*mem_offset(const char *src, size_t offset)
{
	char	*arr;
	size_t	i;

	i = 0;
	src += offset;
	arr = malloc(ft_strlen(src) + 1);
	if (arr && src)
	{
		while (*src)
			arr[i++] = *src++;
		arr[i] = 0;
		return (arr);
	}
	return (NULL);
}

char	*get_and_trim(char **text)
{
	char	*newtext;
	char	*line;
	size_t	l;

	l = ft_linelen(*text);
	if ((*text)[l] == '\n')
		l++;
	line = malloc(sizeof(char) * l + 1);
	newtext = mem_offset(*text, l);
	if (!line || !newtext || l == 0)
		return (free(line), free(newtext), NULL);
	line[l] = 0;
	while (l-- > 0)
		line[l] = (*text)[l];
	free(*text);
	*text = newtext;
	return (line);
}

int	read_file(char **text, int fd)
{
	char	*buffer;
	ssize_t	rbytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer || !*text)
		return (free(buffer), RDERR);
	rbytes = 1;
	while (rbytes > 0)
	{
		rbytes = read(fd, buffer, BUFFER_SIZE);
		if (rbytes == -1)
			return (free(buffer), RDERR);
		buffer[rbytes] = 0;
		*text = ft_strjoin(*text, buffer);
		if (buffer[ft_linelen(buffer)] == '\n')
			return (free(buffer), NEWLINE);
	}
	return (free(buffer), EOF);
}

char	*get_next_line(int fd)
{
	static char	*text[OPEN_MAX];
	char		*line;
	int			file_status;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	if (!text[fd])
		text[fd] = ft_calloc(1, 1);
	file_status = 0;
	if (text[fd][ft_linelen(text[fd])] == 0)
		file_status = read_file(&text[fd], fd);
	if ((*text[fd] == 0 && file_status == EOF) || file_status == RDERR)
		return (free(text[fd]), text[fd] = NULL, NULL);
	line = get_and_trim(&text[fd]);
	return (line);
}
