/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:20:17 by maaliber          #+#    #+#             */
/*   Updated: 2022/11/23 16:38:16 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h> 

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define EOF (-1)
# define NEWLINE 0
# define RDERR (-2)

size_t	ft_strlen(const char *s);
size_t	ft_linelen(char *text);
void	*ft_calloc(size_t n, size_t size);
char	*ft_strjoin(char *txt, char *add);
char	*get_next_line(int fd);

#endif	