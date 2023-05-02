/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:19:35 by gpeta             #+#    #+#             */
/*   Updated: 2023/05/02 18:00:06 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	f_intlen(int n);
static char	*f_spe_case(int i);

char	*ft_itoa(int n)
{
	int		len;
	char	*tab_itoa;

	if (n == 0 || n == -2147483648)
		return (f_spe_case(n));
	len = f_intlen(n);
	tab_itoa = malloc(sizeof(char) * (len + 1));
	if (!tab_itoa)
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		tab_itoa[0] = '-';
	}
	tab_itoa[len] = '\0';
	len--;
	while (n > 0)
	{
		tab_itoa[len] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (tab_itoa);
}

char	*f_spe_case(int i)
{
	if (i == 0)
		return (ft_strdup("0"));
	return (ft_strdup("-2147483648"));
}

int	f_intlen(int n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}
