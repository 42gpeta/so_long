/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:00:30 by gpeta             #+#    #+#             */
/*   Updated: 2022/12/23 15:02:20 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	if ((unsigned char)c == '\0')
		return ((char *)s + ft_strlen(s));
	while (len-- > 0)
	{
		if (s[len] == (unsigned char)c)
			return ((char *)&s[len]);
	}
	return (NULL);
}
