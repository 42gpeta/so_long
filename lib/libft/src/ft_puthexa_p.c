/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:12:57 by gpeta             #+#    #+#             */
/*   Updated: 2023/04/28 16:16:30 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthexa_u(long unsigned int n);

int	ft_puthexa_p(void *n)
{
	int	count_final;

	count_final = 0;
	if (!n)
	{
		write(1, "(nil)", 5);
		return (count_final += 5);
	}
	else
	{
		count_final += write(1, "0x", 2);
		count_final += ft_puthexa_u((long unsigned int)n);
	}
	return (count_final);
}

int	ft_puthexa_u(long unsigned int n)
{
	int		count;
	char	*base;

	base = "0123456789abcdef";
	count = 0;
	if (n >= 0 && n < 16)
	{
		ft_putchar(base[n]);
		count++;
	}
	else
	{
		count += ft_puthexa_u(n / 16);
		count += ft_puthexa_u(n % 16);
	}
	return (count);
}
