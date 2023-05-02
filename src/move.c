/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:37:55 by glodi             #+#    #+#             */
/*   Updated: 2023/05/02 13:59:16 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Move player on top */
void	ft_move_up(t_data *data)
{
	if (data->gen.man.y == data->gen.exit.y
		&& data->gen.man.x == data->gen.exit.x
		&& data->gen.str_tab[data->gen.man.y - 1][data->gen.man.x] != '1')
		ft_move_man_up(data, data->gen.man.y, data->gen.man.x, 'E');
	else if (data->gen.str_tab[data->gen.man.y - 1][data->gen.man.x] == '0'
		|| data->gen.str_tab[data->gen.man.y - 1][data->gen.man.x] == 'C')
	{
		ft_is_collectible1(data, data->gen.man.y - 1, data->gen.man.x);
		ft_move_man_up(data, data->gen.man.y, data->gen.man.x, '0');
	}
	else if (data->gen.str_tab[data->gen.man.y - 1][data->gen.man.x] == 'E')
	{
		ft_move_man_up(data, data->gen.man.y, data->gen.man.x, '0');
		ft_move_exit(data);
	}
}

/* Move player on down */
void	ft_move_down(t_data *data)
{
	if (data->gen.man.y == data->gen.exit.y
		& data->gen.man.x == data->gen.exit.x
		&& data->gen.str_tab[data->gen.man.y + 1][data->gen.man.x] != '1')
		ft_move_man_down(data, data->gen.man.y, data->gen.man.x, 'E');
	else if (data->gen.str_tab[data->gen.man.y + 1][data->gen.man.x] == '0'
		|| data->gen.str_tab[data->gen.man.y + 1][data->gen.man.x] == 'C')
	{
		ft_is_collectible1(data, data->gen.man.y + 1, data->gen.man.x);
		ft_move_man_down(data, data->gen.man.y, data->gen.man.x, '0');
	}
	else if (data->gen.str_tab[data->gen.man.y + 1][data->gen.man.x] == 'E')
	{
		ft_move_man_down(data, data->gen.man.y, data->gen.man.x, '0');
		ft_move_exit(data);
	}
}

/* Move player on left*/
void	ft_move_left(t_data *data)
{
	if (data->gen.man.y == data->gen.exit.y
		&& data->gen.man.x == data->gen.exit.x
		&& data->gen.str_tab[data->gen.man.y][data->gen.man.x - 1] != '1')
		ft_move_man_left(data, data->gen.man.y, data->gen.man.x, 'E');
	else if (data->gen.str_tab[data->gen.man.y][data->gen.man.x - 1] == '0'
		|| data->gen.str_tab[data->gen.man.y][data->gen.man.x - 1] == 'C')
	{
		ft_is_collectible1(data, data->gen.man.y, data->gen.man.x - 1);
		ft_move_man_left(data, data->gen.man.y, data->gen.man.x, '0');
	}
	else if (data->gen.str_tab[data->gen.man.y][data->gen.man.x - 1] == 'E')
	{
		ft_move_man_left(data, data->gen.man.y, data->gen.man.x, '0');
		ft_move_exit(data);
	}
}

/* Move player on right */
void	ft_move_right(t_data *data)
{
	if (data->gen.man.y == data->gen.exit.y
		&& data->gen.man.x == data->gen.exit.x
		&& data->gen.str_tab[data->gen.man.y][data->gen.man.x + 1] != '1')
		ft_move_man_right(data, data->gen.man.y, data->gen.man.x, 'E');
	else if (data->gen.str_tab[data->gen.man.y][data->gen.man.x + 1] == '0'
		|| data->gen.str_tab[data->gen.man.y][data->gen.man.x + 1] == 'C')
	{
		ft_is_collectible1(data, data->gen.man.y, data->gen.man.x + 1);
		ft_move_man_right(data, data->gen.man.y, data->gen.man.x, '0');
	}
	else if (data->gen.str_tab[data->gen.man.y][data->gen.man.x + 1] == 'E')
	{
		ft_move_man_right(data, data->gen.man.y, data->gen.man.x, '0');
		ft_move_exit(data);
	}
}

void	ft_move_exit(t_data *data)
{
	if (data->gen.number_of_C == 0)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
}
