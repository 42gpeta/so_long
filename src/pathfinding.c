/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:48:39 by glodi             #+#    #+#             */
/*   Updated: 2023/04/20 22:31:00 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_flood_fill(t_data *data)
{
    
    t_data *actual;
    char **last;

    actual = data;

    last = actual->generate.string_map_ber_tab;

    last[data->generate.player.pos_y][data->generate.player.pos_x] = '2';
    
    // if (actual[actual->generate.player.pos_y + 1][actual->generate.player.pos_x] == '0'
    // || actual[actual->generate.player.pos_y + 1][actual->generate.player.pos_x] == 'C')
    // // || actual[data->generate.player.pos_y + 1][data->generate.player.pos_x] == 'E')
    // {
    //     data->generate.player.pos_y = 1
    //     data->generate.player.pos_x ;
    // }
    
}

