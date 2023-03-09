/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:45:13 by gpeta             #+#    #+#             */
/*   Updated: 2022/12/23 15:02:20 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	f_in_trim(char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	iword;
	char	*pn;

	if (!s1)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	while (f_in_trim(s1[i], set) && s1[i] != '\0')
		i++;
	while (f_in_trim(s1[j - 1], set) && j > i)
		j--;
	pn = malloc (sizeof(char) * ((j - i) + 1));
	if (!pn)
		return (NULL);
	iword = 0;
	while (i < j)
	{
		pn[iword] = s1[i];
		iword++;
		i++;
	}
	pn[iword] = '\0';
	return (pn);
}

int	f_in_trim(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}
