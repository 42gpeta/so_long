/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:36:58 by gpeta             #+#    #+#             */
/*   Updated: 2023/04/01 18:36:20 by glodi            ###   ########.fr       */
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

// void	ft_message_error(char *message, t_data *data, t_generate *generate) // ? v2
// {
// 	int	i = 0;
// 	write(1, "Error\n", 6);
// 	write(1, message, ft_strlen(message));
// 	write(1, "\n", 1);
// 	if (generate->map.up)
// 		free(generate->map.up);
// 	// if (generate->map.down)
// 		// free(generate->map.down);
// 	// while (generate->string_map_ber_tab[i])
// 	// 	free(generate->string_map_ber_tab[i++]);
// 	// if (generate->string_map_ber_tab)
// 	// 	free(generate->string_map_ber_tab);
// 	if (data->string_map/*  != NULL */)
// 		free(data->string_map);
// 	if (data->mlx_ptr/*  != NULL */)
// 		free(data->mlx_ptr);
// 	exit(EXIT_FAILURE);
// }

void	ft_message_error(char *message, t_data *data, t_generate *generate) // ? v3
{
	int	i = 0;

	i = 0;
	write(1, "Error\n", 6);
	write(1, message, ft_strlen(message));
	write(1, "\n", 1);
	if (generate->fd > 0 && generate->fd < 1024)
	{
		while (generate->string_map_ber_tab[i] != NULL)
			free(generate->string_map_ber_tab[i++]);
		if (generate->string_map_ber_tab)
			free(generate->string_map_ber_tab);
	}
	if (data->string_map/*  != NULL */)
		free(data->string_map);
	if (data->mlx_ptr/*  != NULL */)
		free(data->mlx_ptr);
	exit(EXIT_FAILURE);
}