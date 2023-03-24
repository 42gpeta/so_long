/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:10:51 by gpeta             #+#    #+#             */
/*   Updated: 2022/12/23 15:02:35 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ps;

	i = 0;
	ps = (unsigned char *)s;
	while (i < n)
	{
		if (*ps == (unsigned char)c)
			return (ps);
		i++;
		ps++;
	}
	return (NULL);
}
