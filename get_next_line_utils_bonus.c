/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:20:42 by maaliber          #+#    #+#             */
/*   Updated: 2022/11/23 16:56:50 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (s[n])
		n++;
	return (n);
}

size_t	ft_linelen(char *txt)
{
	size_t	i;

	i = 0;
	if (!txt)
		return (0);
	while (txt[i] != '\n' && txt[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t n, size_t size)
{
	void	*arr;
	size_t	i;

	if (n == 0)
		return (NULL);
	if ((n * size) / n != size)
		return (NULL);
	arr = malloc(n * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < n * size)
		((unsigned char *)arr)[i++] = 0;
	return (arr);
}

char	*ft_strjoin(char *txt, char *add)
{
	char	*arr;
	size_t	i;
	size_t	l;

	if (!txt || !add)
		return (NULL);
	l = ft_strlen(txt) + ft_strlen(add);
	arr = malloc(sizeof(char) * l + 1);
	if (!arr)
		return (NULL);
	i = 0;
	while (txt[i])
	{
		arr[i] = txt[i];
		i++;
	}
	while (*add)
		arr[i++] = *add++;
	arr[i] = 0;
	free(txt);
	return (arr);
}
