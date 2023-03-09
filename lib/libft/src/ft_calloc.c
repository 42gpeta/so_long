/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:44:37 by gpeta             #+#    #+#             */
/*   Updated: 2022/12/23 15:02:49 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*nwtab;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (size && nmemb > SIZE_MAX / size)
		return (NULL);
	nwtab = (void *)malloc((nmemb * size) * sizeof(char));
	if (!nwtab)
		return (NULL);
	ft_memset(nwtab, '\0', nmemb * size);
	return (nwtab);
}
