/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:22:51 by gpeta             #+#    #+#             */
/*   Updated: 2023/03/01 17:50:43 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*f_search_bn(char *stash, char **new_stash)
{
	int		i;
	char	*line;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if ((ft_strchr(stash, '\n') == NULL))
		line = malloc(sizeof(char) * i + 2);
	else
		line = malloc(sizeof(char) * i + 3);
	if (!(line) || !stash)
		return (NULL);
	i = -1;
	while (stash[++i] != '\n')
		line[i] = stash[i];
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	*new_stash = ft_strdup2(ft_strchr(stash, '\n') + 1);
	if (**new_stash == 0)
	{
		free(*new_stash);
		*new_stash = 0;
	}
	return (free(stash), line);
}

char	*f_search_bn2(char *stash, char **new_stash, char *buf)
{
	int		i;
	char	*nline;

	i = ft_strlen(stash) - ft_strlen(ft_strchr(stash, '\n'));
	if (ft_strchr(stash, '\n') == NULL)
		nline = malloc(sizeof(char) * i + 2);
	else
		nline = malloc(sizeof(char) * i + 3);
	if (!nline || !stash)
		return (NULL);
	i = -1;
	while (stash[++i] != '\n')
		nline[i] = stash[i];
	if (stash[i] == '\n')
		nline[i++] = '\n';
	nline[i] = '\0';
	*new_stash = ft_strdup2(ft_strchr(stash, '\n') + 1);
	if (**new_stash == 0)
	{
		free(*new_stash);
		*new_stash = 0;
	}
	free(stash);
	return (free(buf), nline);
}

char	*f_ret_zero(char **stash, char *buf)
{
	char	*line;

	free(buf);
	buf = 0;
	line = 0;
	if (**stash != 0)
	{
		if (ft_strchr(*stash, '\n'))
			return (line = f_search_bn(*stash, stash), line);
		line = ft_strdup2(*stash);
		free(*stash);
		*stash = 0;
		return (line);
	}
	return (line);
}

char	*f_ret(int fd, char **stash, int ret)
{
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (ret)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
			return (NULL);
		buf[ret] = '\0';
		if (ret == 0 && *stash != 0)
			return (f_ret_zero(stash, buf));
		else
		{
			if (!*stash)
				*stash = ft_strdup2(buf);
			else
				*stash = ft_strjoin(*stash, buf);
			if (ft_strchr(*stash, '\n'))
				return (f_search_bn2(*stash, stash, buf));
		}
	}
	return (f_free(stash, &buf), NULL);
}

void	f_free(char **stash, char **buf)
{
	free(*stash);
	free(*buf);
	*stash = 0;
	*buf = 0;
}
