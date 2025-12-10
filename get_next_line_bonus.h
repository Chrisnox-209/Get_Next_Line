/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpietrza <cpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 10:43:01 by cpietrza          #+#    #+#             */
/*   Updated: 2025/12/10 10:56:21 by cpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(const char *str);
int		ft_strlcpy_gnl(char *dest, const char *src, int size);

void	*ft_calloc(size_t nmemb, size_t size);

char	*ft_strchr_gnl(const char *str, int c);
char	*get_next_line(int fd);
char	*ft_free_gnl(char **stash);
char	*ft_strjoin_gnl(char *stash, const char *buffer);

#endif