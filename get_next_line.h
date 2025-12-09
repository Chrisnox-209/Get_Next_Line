/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpietrza <cpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 10:43:01 by cpietrza          #+#    #+#             */
/*   Updated: 2025/12/09 16:29:33 by cpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define FILENAME "file.txt"
#  define BUFFER_SIZE 10000
# endif

# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		ft_strlen(const char *str);
int		ft_strlcpy_gnl(char *dest, const char *src, int size);

void	*ft_calloc(size_t nmemb, size_t size);

char	*ft_strchr_gnl(const char *str, int c);
char	*get_next_line(int fd);
char	*ft_free_gnl(char **stash);
char	*ft_strjoin_gnl(char *stash, const char *buffer);

#endif