/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:36:58 by gpeta             #+#    #+#             */
/*   Updated: 2023/05/01 16:36:09 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_message_error(char *message, t_data *data)
{
	int	i;

	i = 0;
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	if (data->gen.fd > 0 && data->gen.fd < 1024)
	{
		while (data->gen.str_tab
			&& data->gen.str_tab[i] != NULL)
			free(data->gen.str_tab[i++]);
		if (data->gen.str_tab)
			free(data->gen.str_tab);
		i = 0;
		while (data->gen.str_map_pathfinding
			&& data->gen.str_map_pathfinding[i] != NULL)
			free(data->gen.str_map_pathfinding[i++]);
		if (data->gen.str_map_pathfinding)
			free(data->gen.str_map_pathfinding);
	}
	if (data->str_map)
		free(data->str_map);
	if (data->mlx_ptr)
		free(data->mlx_ptr);
	exit(EXIT_FAILURE);
}
