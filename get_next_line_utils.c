/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpietrza <cpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 10:43:20 by cpietrza          #+#    #+#             */
/*   Updated: 2025/12/09 16:45:46 by cpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *stash, const char *buffer)
{
	size_t	size_stash;
	size_t	size_buffer;
	char	*joint;

	size_buffer = ft_strlen(buffer);
	size_stash = ft_strlen(stash);
	joint = malloc(size_buffer + (size_stash + 1));
	if (!joint)
	{
		if (stash)
		{
			free(stash);
			stash = NULL;
		}
		return (NULL);
	}
	if (size_stash > 0)
		ft_strlcpy_gnl(joint, stash, size_stash + 1);
	ft_strlcpy_gnl(joint + size_stash, buffer, size_buffer + 1);
	free(stash);
	return (joint);
}

int	ft_strlcpy_gnl(char *dest, const char *src, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (src[j])
		j++;
	if (size == 0)
		return (j);
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (j);
}

char	*ft_free_gnl(char **stash)
{
	if (stash && *stash)
	{
		free(*stash);
		*stash = NULL;
	}
	return (NULL);
}
