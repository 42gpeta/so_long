/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:36:58 by gpeta             #+#    #+#             */
/*   Updated: 2023/03/30 19:06:18 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	ft_message_error(char *message) // ? v1
// {
// 	write(1, "Error\n", 6);
// 	write(1, message, ft_strlen(message));
// 	write(1, "\n", 1);
// 	exit(EXIT_FAILURE);
// }

void	ft_message_error(char *message, t_data *data, t_generate *generate) // ? v2
{
	write(1, "Error\n", 6);
	write(1, message, ft_strlen(message));
	write(1, "\n", 1);
	if (generate->map.up)
		free(generate->map.up);
	if (generate->map.down)
		free(generate->map.down);
	if (data->string_map != NULL)
		free(data->string_map);
	if (data->mlx_ptr != NULL)
		free(data->mlx_ptr);
	exit(EXIT_FAILURE);
}