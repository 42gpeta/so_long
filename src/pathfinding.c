/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:48:39 by glodi             #+#    #+#             */
/*   Updated: 2023/05/02 12:30:20 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Fill a box with '2' */
void	ft_pathfinding_move(t_data *data, int y, int x)
{
	ft_is_collectible2(data, y, x);
	data->gen.str_map_pathfinding[y][x] = '2';
	ft_pathfinding_flood(data, y, x);
}

/* Fill the map with '2' */
void	ft_pathfinding_flood(t_data *data, int y, int x)
{
	if ((data->gen.str_map_pathfinding[y - 1][x] == '0'
		|| data->gen.str_map_pathfinding[y - 1][x] == 'C'
		|| data->gen.str_map_pathfinding[y - 1][x] == 'E'))
		ft_pathfinding_move(data, y - 1, x);
	if ((data->gen.str_map_pathfinding[y + 1][x] == '0'
		|| data->gen.str_map_pathfinding[y + 1][x] == 'C'
		|| data->gen.str_map_pathfinding[y + 1][x] == 'E'))
		ft_pathfinding_move(data, y + 1, x);
	if ((data->gen.str_map_pathfinding[y][x - 1] == '0'
		|| data->gen.str_map_pathfinding[y][x - 1] == 'C'
		|| data->gen.str_map_pathfinding[y][x - 1] == 'E'))
		ft_pathfinding_move(data, y, x - 1);
	if ((data->gen.str_map_pathfinding[y][x + 1] == '0'
		|| data->gen.str_map_pathfinding[y][x + 1] == 'C'
		|| data->gen.str_map_pathfinding[y][x + 1] == 'E'))
		ft_pathfinding_move(data, y, x + 1);
}

/* Look if 'E' and 'C' are accesible */
void	ft_pathfinding_check(t_data *data)
{
	ft_pathfinding_flood(data, data->gen.man.y, data->gen.man.x);
	if (data->gen.number_of_e_pathfinding != 0)
		ft_message_error("No way to exit !", data);
	if (data->gen.number_of_c_pathfinding != 0)
		ft_message_error("No way to all collectibles", data);
}
