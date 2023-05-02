/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_parameters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:11:17 by gpeta             #+#    #+#             */
/*   Updated: 2023/05/02 12:24:26 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_man_up(t_data *data, int y, int x, char letter)
{
		data->gen.str_tab[y - 1][x] = 'P';
		data->gen.str_tab[y][x] = letter;
		data->gen.man.y -= 1;
		data->gen.man.nb_move++;
}

void	ft_move_man_down(t_data *data, int y, int x, char letter)
{
		data->gen.str_tab[y + 1][x] = 'P';
		data->gen.str_tab[y][x] = letter;
		data->gen.man.y += 1;
		data->gen.man.nb_move++;
}

void	ft_move_man_left(t_data *data, int y, int x, char letter)
{
		data->gen.str_tab[y][x - 1] = 'P';
		data->gen.str_tab[y][x] = letter;
		data->gen.man.x -= 1;
		data->gen.man.nb_move++;
}

void	ft_move_man_right(t_data *data, int y, int x, char letter)
{
		data->gen.str_tab[y][x + 1] = 'P';
		data->gen.str_tab[y][x] = letter;
		data->gen.man.x += 1;
		data->gen.man.nb_move++;
}
