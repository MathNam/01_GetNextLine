/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:20:33 by maaliber          #+#    #+#             */
/*   Updated: 2022/11/23 14:15:19 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		buffer[rbytes] = 0;
		*text = ft_strjoin(*text, buffer);
		if (buffer[ft_linelen(buffer)] == '\n')
			return (free(buffer), NEWLINE);
	}
	if (rbytes == -1)
		return (free(buffer), RDERR);
	return (free(buffer), EOF);
}

char	*get_next_line(int fd)
{
	static char	*text;
	char		*line;
	int			file_status;

	file_status = read(fd, 0, 0);
	if (BUFFER_SIZE <= 0 || file_status < 0)
		return (NULL);
	if (!text)
		text = ft_calloc(1, 1);
	if (text[ft_linelen(text)] == 0)
		file_status = read_file(&text, fd);
	if ((*text == 0 && file_status == EOF) || file_status == RDERR)
		return (free(text), text = NULL, NULL);
	line = get_and_trim(&text);
	return (line);
}
