/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:23:42 by gpeta             #+#    #+#             */
/*   Updated: 2023/05/02 18:46:00 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Checks if the next case is a 'C' for str_tab */
void	ft_is_collectible1(t_data *data, int y, int x)
{
	if (data->gen.str_tab[y][x] == 'C')
		data->gen.number_of_c--;
}

/* Checks if the next case is a 'C' for str_map_pathfinding */
void	ft_is_collectible2(t_data *data, int y, int x)
{
	if (data->gen.str_map_pathfinding[y][x] == 'C')
		data->gen.number_of_c_pathfinding--;
}
