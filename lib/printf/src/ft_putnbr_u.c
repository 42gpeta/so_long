/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 18:29:54 by gpeta             #+#    #+#             */
/*   Updated: 2022/12/29 14:29:11 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 0 && n <= 9)
	{
		ft_putchar(n + '0');
		count++;
	}
	else
	{
		count += ft_putnbr_u(n / 10);
		count += ft_putnbr_u(n % 10);
	}
	return (count);
}
