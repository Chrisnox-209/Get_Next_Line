/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpietrza <cpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 10:43:16 by cpietrza          #+#    #+#             */
/*   Updated: 2025/12/09 16:45:43 by cpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr_gnl(const char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
		{
			return ((char *)&str[i]);
		}
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&str[i]);
	return (NULL);
}

char	*ft_extract_line(char *stash)
{
	char	*line;
	int		i;
	int		len_total;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	len_total = i;
	if (len_total == 0)
		return (NULL);
	line = malloc(len_total + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < len_total)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_clean_stash(char *stash)
{
	int		i;
	int		j;
	int		size;
	char	*new_stash;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] != '\n')
		return (ft_free_gnl(&stash));
	size = ft_strlen(stash) - ++i;
	if (size <= 0)
		return (ft_free_gnl(&stash));
	new_stash = malloc(size + 1);
	if (!new_stash)
		return (ft_free_gnl(&stash));
	j = -1;
	while (++j < size)
		new_stash[j] = stash[i + j];
	new_stash[j] = '\0';
	return (free(stash), new_stash);
}

char	*ft_process_stash(char **stash, char **line)
{
	*line = ft_extract_line(*stash);
	if (!*line && *stash)
		return (ft_free_gnl(stash));
	*stash = ft_clean_stash(*stash);
	return (*line);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		read_byte;
	static char	*stash;
	char		*line;

	read_byte = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (ft_strchr_gnl(stash, '\n') != NULL || read_byte == 0)
		{
			return (ft_process_stash(&stash, &line));
		}
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte == -1)
			return (ft_free_gnl(&stash));
		buffer[read_byte] = '\0';
		stash = ft_strjoin_gnl(stash, buffer);
		if (!stash)
			return (NULL);
	}
	return (NULL);
}
