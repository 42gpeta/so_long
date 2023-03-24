/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:27:23 by gpeta             #+#    #+#             */
/*   Updated: 2022/12/23 15:02:22 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned int	res;

	i = 0;
	res = (unsigned char)s1[i] - (unsigned char)s2[i];
	if (n == 0)
		return (0);
	while (i < n - 1 && s1[i])
	{
		if (s1[i] < s2[i])
		{
			res = (unsigned char)s1[i] - (unsigned char)s2[i];
			return (res);
		}
		else if (s1[i] > s2[i])
		{
			res = (unsigned char)s1[i] - (unsigned char)s2[i];
			return (res);
		}
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
