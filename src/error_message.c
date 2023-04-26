/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:36:58 by gpeta             #+#    #+#             */
/*   Updated: 2023/04/26 17:30:03 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_message_error(char *message, t_data *data) // ? v5
{
	int	i;

	i = 0;
	write(1, "Error\n", 6);
	write(1, message, ft_strlen(message));
	write(1, "\n\n", 2);
	if (data->generate.fd > 0 && data->generate.fd < 1024)
	{
		while (data->generate.string_map_ber_tab && data->generate.string_map_ber_tab[i] != NULL)
			free(data->generate.string_map_ber_tab[i++]);
		if (data->generate.string_map_ber_tab)
			free(data->generate.string_map_ber_tab);
		i = 0;
		while (data->generate.string_map_pathfinding && data->generate.string_map_pathfinding[i] != NULL)
			free(data->generate.string_map_pathfinding[i++]);
		if (data->generate.string_map_pathfinding)
			free(data->generate.string_map_pathfinding);
	}
	if (data->string_map)
		free(data->string_map);
	if (data->mlx_ptr)
		free(data->mlx_ptr);
	exit(EXIT_FAILURE);
}