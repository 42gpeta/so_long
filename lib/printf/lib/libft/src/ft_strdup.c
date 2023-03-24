/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:33:43 by gpeta             #+#    #+#             */
/*   Updated: 2022/12/23 15:02:26 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
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
