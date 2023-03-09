/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:45:07 by gpeta             #+#    #+#             */
/*   Updated: 2022/12/23 15:02:19 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*f_malloc(char const *s, size_t begin, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ns;
	size_t	i;

	if (!s)
		return (NULL);
	ns = f_malloc(s, start, len);
	if (!ns)
		return (NULL);
	i = 0;
	while (i < len && start < ft_strlen(s))
	{
		ns[i] = s[start++];
		i++;
	}
	ns[i] = '\0';
	return (ns);
}

char	*f_malloc(char const *s, size_t begin, size_t len)
{
	char	*ns;
	size_t	slen;

	slen = ft_strlen(s);
	if (begin > slen)
	{
		ns = malloc(sizeof(char));
		if (!ns)
			return (NULL);
		ns[0] = '\0';
		return (ns);
	}
	else if (begin + len > slen)
		ns = malloc(sizeof(char) * (slen - begin + 1));
	else
		ns = malloc(sizeof(char) * (len + 1));
	return (ns);
}
