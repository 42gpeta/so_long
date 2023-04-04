/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:27:17 by gpeta             #+#    #+#             */
/*   Updated: 2023/04/04 19:22:45 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define INT_MAX 2147483647

/* INCLUDE */
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdint.h>

/* BUFFER */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

/* FUNCTION */
char	*get_next_line(int fd);
char	*f_search_bn(char *stash, char **new_stash);
char	*f_search_bn2(char *stash, char **new_stash, char *buf);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strdup2(char *s);
char	*f_ret_zero(char **stash, char *buf);
char	*f_ret(int fd, char **stash, int ret);
void	f_free(char **stash, char **buf);

#endif