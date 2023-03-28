/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:36:58 by gpeta             #+#    #+#             */
/*   Updated: 2023/03/28 15:39:01 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_message_error(char *message)
{
	write(1, message, ft_strlen(message));
	write(1, "\n", 1);
	exit(EXIT_FAILURE);
}