/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_check.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:03:46 by gpeta             #+#    #+#             */
/*   Updated: 2023/04/28 16:16:30 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	f_check(va_list args, char c)
{
	int		len;

	len = 0;
	if (c == 'c')
		len = ft_putchar(va_arg(args, int));
	else if (c == 's')
		len = ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		len = ft_puthexa_p(va_arg(args, void *));
	else if (c == 'd')
		len = ft_putnbr(va_arg(args, int));
	else if (c == 'i')
		len = ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		len = ft_putnbr_u(va_arg(args, unsigned int));
	else if (c == 'x')
		len = ft_puthexa(va_arg(args, unsigned int), 'x');
	else if (c == 'X')
		len = ft_puthexa(va_arg(args, unsigned int), 'X');
	else if (c == '%')
		len = ft_putchar('%');
	va_end(args);
	return (len);
}
