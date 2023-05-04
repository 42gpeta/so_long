/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:23:42 by gpeta             #+#    #+#             */
/*   Updated: 2023/05/04 14:39:03 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Checks if the next case is a 'C' for str_tab */
void	ft_is_collectible1(t_data *data, int y, int x)
{
	if (data->gen.str_tab[y][x] == 'C')
		data->gen.number_of_c--;
}

/* Checks if the next case is a 'C' or 'E' for str_map_pathfinding */
void	ft_is_collectible2(t_data *data, int y, int x)
{
	if (data->gen.str_map_pathfinding[y][x] == 'C')
		data->gen.number_of_c_pathfinding--;
	if (data->gen.str_map_pathfinding[y][x] == 'E')
		data->gen.number_of_e_pathfinding--;
}

void	ft_init_c_and_e(t_data *data)
{
	data->gen.number_of_c_pathfinding = data->gen.number_of_c;
	data->gen.number_of_e_pathfinding = data->gen.number_of_e;
	
}
