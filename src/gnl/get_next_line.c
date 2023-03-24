/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:47:19 by gpeta             #+#    #+#             */
/*   Updated: 2023/03/01 12:41:01 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash = 0;
	int			ret;

	ret = BUFFER_SIZE;
	if (fd < 0 || BUFFER_SIZE > INT_MAX - 1 || BUFFER_SIZE < 1
		|| read(fd, NULL, 0) == -1)
		return (NULL);
	if (ft_strchr(stash, '\n'))
		return (f_search_bn(stash, &stash));
	return (f_ret(fd, &stash, ret));
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	if (*s == '\0')
		return (NULL);
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*join;
	int		len;

	len = (int)ft_strlen(s1) + (int)ft_strlen(s2);
	join = NULL;
	join = malloc(sizeof(char) * (len + 1));
	if (!join)
		return (NULL);
	i = 0;
	while (s1[i] && s1[i] != '\0')
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] && s2[j] != '\0')
	{
		join[i + j] = s2[j];
		j++;
	}
	join [i + j] = '\0';
	free(s1);
	return (join);
}

char	*ft_strdup2(char *s)
{
	size_t	i;
	char	*ps;
	size_t	len;

	len = ft_strlen(s);
	ps = malloc(sizeof(char) * len + 1);
	if (!ps)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ps[i] = s[i];
		i++;
	}
	ps[i] = '\0';
	return (ps);
}
