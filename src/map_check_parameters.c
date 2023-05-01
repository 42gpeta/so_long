/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_parameters.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:50:11 by glodi             #+#    #+#             */
/*   Updated: 2023/05/01 19:16:10 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*** Checks if top of map is surronded by '1' */
void	ft_check_surrounded_by_one_up(t_data *data)
{
	int		x;

	x = 0;
	while (data->gen.str_tab[0][x])
	{
		if (data->gen.str_tab[0][x] != '1')
			ft_message_error("Top side of map isn't a wall of '1'", data);
		x++;
	}
}

/*** Checks if bottom of map is surronded by '1' */
void	ft_check_surrounded_by_one_bottom(t_data *data)
{
	int		x;

	x = 0;
	while (data->gen.str_tab[data->row_size_map - 1][x])
	{
		if (data->gen.str_tab[data->row_size_map - 1][x] != '1')
			ft_message_error("Bottom side of map isn't a wall of '1'", data);
		x++;
	}
}

/*** Checks if left side of map is surronded by '1' */
void	ft_check_surrounded_by_one_left(t_data *data)
{
	int		y;

	y = 0;
	while (data->gen.str_tab[y][0] && y < data->row_size_map - 1)
	{
		if (data->gen.str_tab[y][0] != '1')
			ft_message_error("Left side of map isn't a wall of '1'", data);
		y++;
	}
}

/*** Checks if right side of map is surronded by '1' */
void	ft_check_surrounded_by_one_right(t_data *data)
{
	int		y;

	y = 0;
	if (!(data->gen.str_tab[y][data->colomn_size_map - 1]))
		ft_message_error("The right side is smaller than the left side", data);
	while (data->gen.str_tab[y][data->colomn_size_map]
		&& y < data->row_size_map - 1)
	{
		if (data->gen.str_tab[y][data->colomn_size_map] != '1')
			ft_message_error("Right side of map isn't a wall of '1'", data);
		y++;
	}
}
